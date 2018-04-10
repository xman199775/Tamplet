#include <QApplication>
//#include <QQmlApplicationEngine>
#include <system/serverconnections.h>
#include <repositories/employeerepository.h>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
<<<<<<< HEAD
    serverConnections::getInstance()->creatServerConnection("general","QMYSQL","127.0.0.1","root","root","template");
=======
    serverConnections::getInstance()->creatServerConnection("general","QMYSQL","127.0.0.1","root","root","tamplete", 8889);
>>>>>>> c520bcc496df2e06d5af6c5abbb736e4842053ad
    serverConnections::getInstance()->connectToServer("general");
    /*QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;*/

    return app.exec();
}
