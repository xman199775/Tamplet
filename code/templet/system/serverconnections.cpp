#include "serverconnections.h"
serverConnections *serverConnections::instance=NULL;
serverConnections::serverConnections()
{

}

void  serverConnections::creatServerConnection(QString serverName,QString driver,QString hostName,QString userName,QString passWord,QString dataBaseName, int port)
{
    server *temp=new server( driver, hostName, userName, passWord, dataBaseName, port);
    allServer.insert(serverName,temp);
}
bool serverConnections::connectToServer(QString serverName)
{
    if(allServer.value(serverName)->connect())
    {
        numberOfConnections+=1;
        return true;
    }
    else
    {
        return false;
    }

}
void  serverConnections::disconnectFromServer(QString serverName)
{
    if(allServer.value(serverName)->disconnect())
    {
        numberOfConnections-=1;
    }
}
QSqlDatabase serverConnections::getserverConnections(QString serverName)
{

    if(!allServer.value(serverName)->connectSuccess)
    {
        qDebug()<<"worng open at server : "<<serverName<<"  you Should connect first";
    }
    return allServer.value(serverName)->mydata;

}

serverConnections* serverConnections::getInstance()
{
    if(instance==NULL)
    {
        instance=new serverConnections();
    }
    return instance;
}
