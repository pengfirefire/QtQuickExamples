#include <QApplication>
#include <QVBoxLayout>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    // 加载数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // 配置数据库主机名称
    db.setHostName("localhost");
    // 配置数据库名称
    db.setDatabaseName("medical_monitor");
    // 用户名密码
    db.setUserName("doctor2");
    db.setPassword("123456");
    // 打开链接/登陆
    bool openOk = db.open();

    if (openOk)
    {
        qDebug()<<"登陆成功";
    }
    else
    {
        qDebug()<<"登陆错误";
    }

    QSqlQuery query(db);
    if (openOk)
    {
        query.exec("SELECT name FROM doctor WHERE uid = 'doctor1'");

        qDebug()<<"size: "<<query.size();

        while (query.next())
        {
            qDebug()<<query.value("name").toString();
        }
    }


    return  a.exec();
}

