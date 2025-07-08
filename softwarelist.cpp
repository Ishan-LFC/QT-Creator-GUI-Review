//Implementation SoftwareList
#include "softwarelist.h"

SoftwareList::SoftwareList()
{

}

void SoftwareList::addReview(Software r)
{
    r_softwareList.append(r);
}

QList<Software> SoftwareList::getSoftwareReviewList() const
{
    return r_softwareList;
}

QString SoftwareList::toString() const
{
    QString outS;

    for (int count = 0; count < this->size(); count++) {
        outS += this->at(count).toString() + "\n\n";
    }

    return outS;
}
