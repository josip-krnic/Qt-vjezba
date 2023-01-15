#include "reciever.h"

#include <QDebug>

reciever::reciever(QObject *parent)
    : QObject{parent}
{
    m_device_list = QCanBus::instance()->availableDevices("socketcan");

    if(m_device_list.isEmpty())return;

    m_device = QCanBus::instance()->createDevice(QStringLiteral("socketcan"),
                                               m_device_list[0].name());
    m_device->connectDevice();

    connect(m_device, &QCanBusDevice::framesReceived, this, &reciever::displayFrame);
}

void reciever::displayFrame() {

    m_frame = m_device->readFrame();
    QString frame_string = m_frame.toString();
    qDebug() << frame_string;
}
