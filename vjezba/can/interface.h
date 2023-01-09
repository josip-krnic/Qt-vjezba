#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include <QtQml>
#include "functions.h"

class Interface : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Interface(QObject *parent = nullptr);


signals:


public slots:
    void setData(QVariant msg, QVariant id, CanClass can);

private:

}; 

#endif // INTERFACE_H
