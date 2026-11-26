#include "getdomainip.h"
#include "ui_getdomainip.h"

GetDomainIP::GetDomainIP(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GetDomainIP)
{
    ui->setupUi(this);
    ui->lineEdit_InputUrl->setText("www.126.com");
}

GetDomainIP::~GetDomainIP()
{
    delete ui;
}

QString GetDomainIP::ProtocolTypeName(QAbstractSocket::NetworkLayerProtocol ProtocolType)
{
    switch(ProtocolType){
    case QAbstractSocket::IPv4Protocol:
        return "IPv4 Protocol";
    case QAbstractSocket::IPv6Protocol:
        return "IPv6 Protocol";
    case QAbstractSocket::AnyIPProtocol:
        return "Any IP Protocol";
    default:
        return "Unknown Network Layer Protocol";
    }
}

void GetDomainIP::LookUpHostInfoFunc(const QHostInfo &host)
{
    QList<QHostAddress> addressList=host.addresses();
    for(int i=0;i<addressList.count();i++){
        QHostAddress Host=addressList.at(i);
        ui->plainTextEdi_DomainIP->appendPlainText("协议类型："+ProtocolTypeName(Host.protocol()));
        ui->plainTextEdi_DomainIP->appendPlainText("本地ip地址："+Host.toString());

    }
}

void GetDomainIP::on_pushButton_clearData_clicked()
{
    ui->plainTextEdi_DomainIP->clear();
}


void GetDomainIP::on_pushButton_GetDomainIP_clicked()
{
    QString strHostName=ui->lineEdit_InputUrl->text();
    ui->plainTextEdi_DomainIP->appendPlainText("你所查询主机信息："+strHostName);
    QHostInfo::lookupHost(strHostName,this,SLOT(LookUpHostInfoFunc(QHostInfo)));
}










