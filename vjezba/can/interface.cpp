#include "interface.h"
#include "functions.h"
#include <iostream>

Interface::Interface(QObject *parent)
    : QObject{parent}
{

}

void Interface::setData(QVariant msg, QVariant id, CanClass can)
{
    can.sendMessage(msg.toByteArray());
    can.setId(id.toInt());
}
