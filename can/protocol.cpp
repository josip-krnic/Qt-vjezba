#include "protocol.h"
#include <QDebug>

Protocol::Protocol(QObject *parent)
    : QObject{parent}
{
    device = QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("vcan0"), &errorString);

    if (!device)
        qDebug() << errorString;

    else
        device->connectDevice();
}

Protocol::~Protocol()
{
    device->disconnectDevice();
    qDebug() << "Device disconnected";
}

int Protocol::sendMessage()
{
    QByteArray payload(_message);
    frame.setPayload(payload);
    if(!device->writeFrame(frame))
        qDebug() << "Error";

    return 0;
}

void Protocol::setData(QByteArray message, quint32 id)
{
    qDebug() << message;
    qDebug() << id;
    _id = id;
    _message = message;
    sendMessage();
}

int Protocol::getMessage()
{
    frame = device->readFrame();

    return 0;
}
