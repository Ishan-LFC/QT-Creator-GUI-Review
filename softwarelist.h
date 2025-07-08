//Interface SoftwareList
#ifndef SOFTWARELIST_H
#define SOFTWARELIST_H
#include "software.h"
#include <QList>

class SoftwareList : public QList<Software>
{
public:
    SoftwareList();
    void addReview(Software r);
    QList<Software> getSoftwareReviewList() const;
    QString toString() const;
private:
         //container
    QList<Software> r_softwareList;
};

#endif // SOFTWARELIST_H
