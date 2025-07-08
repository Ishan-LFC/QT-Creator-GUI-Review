//Implementation Gui
#include "gui.h"
#include "software.h"
//#include "softwarelist.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
#include <QLayout>
#include <QDateEdit>
#include <QTextStream>
#include <QGroupBox>
#include <QRadioButton>
#include <QList>

//constructor
Gui::Gui(QWidget *parent)
    : QWidget(parent), text{new QGroupBox("Fill in the data and click add")},
    recommendedButton{new QRadioButton("recommended")},
    addButton{new QPushButton("Add")}, displayButton{new QPushButton("Display")},
    nameG{new QLineEdit}, calendarDate{new QDateEdit}
{

    displayGui();
    // Connect Signals and Slots
    connect(nameG, &QLineEdit::textChanged, this, &Gui::process);
    connect(addButton, &QPushButton::clicked, this, &Gui::addConsole);
    connect(displayButton, &QPushButton::clicked, this, &Gui::displayConsole);
}

//Destructor
//Gui::~Gui()
//{

//}

//Process name text
void Gui::process()
{
    if (nameG ->text().size()!=0)
    {
        addButton ->setEnabled(true);
    }
}

//Member function to process buttons
void Gui::addConsole()
{
    //clearing input widgets
    nameG->clear();

    //setting cursor focus
    nameG->setFocus();
    displayButton->setFocus();

    //Enable buttons
    addButton->setEnabled(false);
    //displayButton->setEnabled(true);
    QMessageBox::information(this, "Review", "Review Added");
}

Software Gui::getSoftware() const
{
    return software;
}

//Display to console
void Gui::displayConsole()
{

    QTextStream cout(stdout);
    //Software software;

    //Display Details
    cout << "Review Details: " << Qt::endl;
    cout << "Includes Name of Software and Date of the Software Reviewed: " << Qt::endl;

    software.setName(nameG->text());
    software.setDate(calendarDate->dateTime());
    cout << software.toString() << Qt::endl;

    cout << "To display to console, re-enter information and press display" << Qt::endl;

    QMessageBox::information(this, "Displayed", "Displayed to console");
}

//Setup Gui and layout of Gui
void Gui::displayGui()
{
    //Display title of Gui window
    setWindowTitle("Software Review");

    QLabel* nameLabel{new QLabel("Add Name")};
    QLabel* dateLabel{new QLabel("Provide a Date")};
    QLabel* textLabel{new QLabel("Fill in the data and click add")};
    calendarDate = new QDateEdit(QDate::currentDate());

    //create layout of widget
    QGridLayout* layout{new QGridLayout(this)};
    layout->addWidget(textLabel, 0, 0);
    layout->addWidget(nameLabel, 1, 0);
    layout->addWidget(nameG, 1, 1);
    layout->addWidget(dateLabel, 2, 0);
    layout->addWidget(calendarDate, 2, 1);
    layout->addWidget(recommendedButton, 3, 0, 1, 2);
    layout->addWidget(addButton, 4, 0, 1, 2);
    layout->addWidget(displayButton, 5, 0, 1, 2);

    //Resets buttons after use
    addButton->setEnabled(false);
    //displayButton->setEnabled(false);

    //Sets Gridlayout after created
    this->setLayout(layout);
}
