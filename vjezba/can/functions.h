#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QCanBus>
#include <QString>

class CanClass
{

private:
    QString errorString;
    QCanBusDevice *device;
    QByteArray payload;

public:
    QByteArray message;
    QCanBusFrame frame;
    CanClass();
    int setId(int Id);
    int sendMessage(QByteArray message);
};

#endif
