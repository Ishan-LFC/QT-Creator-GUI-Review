//Interface Gui
#ifndef GUI_H
#define GUI_H

#include "software.h"
#include <QWidget>
#include <QDialog>
#include <QObject>
class QPushButton;
class QLineEdit;
class QComboBox;
class QDateEdit;
class QGroupBox;
class QRadioButton;

class Gui : public QWidget
{
    Q_OBJECT
public:
    explicit Gui(QWidget *parent = nullptr);//Q_OBECT requires an explicit public constructor
    //~Gui();
    Software getSoftware() const;

private slots:
    void displayConsole();
    void process();
    void addConsole();
    //void recommendedReview();
private:
    void displayGui();
    QPushButton *addButton;
    QPushButton *displayButton;
    QLineEdit *nameG;
    QDateEdit *calendarDate;
    QGroupBox *text;
    QRadioButton *recommendedButton;
    Software software;
};

#endif // GUI_H
