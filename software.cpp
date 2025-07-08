//Implementation Software
#include "software.h"
#include "softwarelist.h"
#include <QString>

Software::Software()
{

}

Software::Software(QString n, QDateTime d): name(n), reviewDate(d)
{

}

//Setter
void Software::setName(QString n)
{
    name = n;
}

//Getter
QString Software::getName() const
{
    return name;
}

void Software::setDate(QDateTime d)
{
    reviewDate = d;
}


QDateTime Software::getDate() const
{
    return reviewDate;
}

//Displays
QString Software::toString() const
{
    QString info;
    QTextStream os(&info);
    os << "Name: " << name << " Date: " << reviewDate.toString("dd.MM.yyyy") <<Qt::endl;
    return info;
}

