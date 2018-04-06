<<<<<<< HEAD
/*#include "view/mainwindow.h"
#include <QApplication>

=======
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "system/serverconnections.h"
>>>>>>> 9a75bec966d72e025083737f4ff4e359bf615871
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
*/
