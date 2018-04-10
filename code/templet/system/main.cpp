#include <QApplication>
//#include <QQmlApplicationEngine>
#include <system/serverconnections.h>
#include <repositories/employeerepository.h>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    serverConnections::getInstance()->creatServerConnection("general","QMYSQL","127.0.0.1","root","root","template");
    serverConnections::getInstance()->connectToServer("general");
    /*QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;*/

    return app.exec();
}
