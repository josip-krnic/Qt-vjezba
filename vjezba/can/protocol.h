#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "qqml.h"
#include <QObject>
#include <QCanBus>
#include <QString>

class Protocol : public QObject
{
    Q_OBJECT
    QML_ELEMENT

private:
    QString errorString;
    QCanBusDevice *device;
    QByteArray payload;

public:
    QByteArray _message;
    QCanBusFrame frame;
    int sendMessage();
    explicit Protocol(QObject *parent = nullptr);

signals:

public slots:
    void setData(QByteArray msg, int id);
};

#endif // PROTOCOL_H
