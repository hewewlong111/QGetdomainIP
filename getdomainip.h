#ifndef GETDOMAINIP_H
#define GETDOMAINIP_H

#include <QDialog>
#include <QHostInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class GetDomainIP;
}
QT_END_NAMESPACE

class GetDomainIP : public QDialog
{
    Q_OBJECT

public:
    explicit GetDomainIP(QWidget *parent = nullptr);
    ~GetDomainIP() override;

    //获取ip地址类型
    QString ProtocolTypeName(QAbstractSocket::NetworkLayerProtocol pro);

private slots:
    void on_pushButton_clearData_clicked();

    void on_pushButton_GetDomainIP_clicked();

    //获取ip地址列表
    void LookUpHostInfoFunc(const QHostInfo &host);

private:
    Ui::GetDomainIP *ui;
};
#endif // GETDOMAINIP_H
