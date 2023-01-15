#ifndef RECIEVER_H
#define RECIEVER_H

#include <QObject>
#include <QCanBus>

class reciever : public QObject
{
    Q_OBJECT
public:
    explicit reciever(QObject *parent = nullptr);
    void parseMessage(QCanBusFrame);
    QCanBusDevice *m_device;
    QCanBusFrame m_frame;
    QList<QCanBusDeviceInfo>m_device_list;

signals:
    void signalFrame(QString data);

public slots:
    void displayFrame();
};


#endif // RECIEVER_H
