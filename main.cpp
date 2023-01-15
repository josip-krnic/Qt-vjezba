#include <QApplication>
#include <QQmlApplicationEngine>
#include <QCanBus>
#include <iostream>
#include  <QQmlContext>

#include "can/protocol.h"
#include "can/reciever.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<Protocol>("Protocol", 1, 0, "Protocol");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    reciever recieveFramesObj;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("recieveFramesObj", &recieveFramesObj);

    return app.exec();
}
