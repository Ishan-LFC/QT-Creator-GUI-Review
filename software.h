//Interface Software
#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <QString>
#include <QDateEdit>

class Software//Class in Capital Letters
{
public:
    Software();
    Software(QString n, QDateTime d);
    void setName(QString n);
    void setDate(QDateTime d);
    QString getName() const;
    QDateTime getDate() const;
    QString toString() const;//Allow inherited functions to invoke new toString
private:
    QString name;
    QDateTime reviewDate;

};

#endif // SOFTWARE_H
