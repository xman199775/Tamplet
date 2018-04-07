#ifndef SERVERCONNECTIONS_H
#define SERVERCONNECTIONS_H
#include <QtSql>
#include <QMap>
#include <QDebug>
class serverConnections
{
private:
    struct server
    {
        QSqlDatabase mydata;
        bool connectSuccess=false;
        server(QString driver,QString hostName,QString userName,QString passWord,QString dataBaseName,int port)
        {
            mydata= QSqlDatabase::addDatabase(driver);
            mydata.setHostName(hostName);
            mydata.setUserName(userName);
            mydata.setPassword(passWord);
            mydata.setDatabaseName(dataBaseName);
            mydata.setPort(port);
        }
        bool connect()
        {
            if(mydata.open())
            {
                connectSuccess=true;
                return true;
            }
            else
            {
                qDebug()<<mydata.lastError().text();
                connectSuccess=false;
                return false;
            }
        }

        bool disconnect()
        {
            if(connectSuccess)
            {
                mydata.close();
                return true;
            }
            return false;
        }

    };
    int numberOfConnections=0;
    QMap<QString,server*> allServer;
    serverConnections();
    static serverConnections *instance;

public:
    void creatServerConnection(QString serverName, QString driver, QString hostName, QString userName, QString passWord, QString dataBaseName, int port=3306);
    bool connectToServer(QString serverName);
    void disconnectFromServer(QString serverName);
    QSqlDatabase getserverConnections(QString serverName);
    static serverConnections *getInstance();


};

#endif // SERVERCONNECTIONS_H
