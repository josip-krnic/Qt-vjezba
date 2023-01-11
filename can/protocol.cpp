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

int Protocol::sendMessage()
{
    //frame.setFrameId(8);
    QByteArray payload(_message);
    frame.setPayload(payload);
    device->writeFrame(frame);

    frame = device->readFrame();
    return 0;
}

void Protocol::setData(QByteArray message, int id)
{
    qDebug() << message;
    qDebug() << id;
    _id = id;
    _message = message;
    sendMessage();
}
