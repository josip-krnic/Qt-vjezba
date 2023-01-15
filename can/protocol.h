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
    QByteArray _message;
    QCanBusFrame frame;
    quint32 _id;

public:
    int sendMessage();
    int getMessage();
    explicit Protocol(QObject *parent = nullptr);
    ~Protocol();

signals:

public slots:
    void setData(QByteArray msg, quint32 id);
};

#endif // PROTOCOL_H
