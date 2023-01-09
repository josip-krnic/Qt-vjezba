#include "functions.h"
#include <QDebug>

CanClass::CanClass()
{
    device = QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("vcan0"), &errorString);

    if (!device)
        qDebug() << errorString;

    else
        device->connectDevice();
}

int CanClass::setId(int Id)
{
    frame.setFrameId(Id);
    return 0;
}

int CanClass::sendMessage(QByteArray message)
{
    QByteArray payload(message);
    frame.setPayload(payload);
    device->writeFrame(frame);
    frame = device->readFrame();

    return 0;
}
