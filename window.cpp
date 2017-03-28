
#include <QtWidgets>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>
#include<QGridLayout>

#include "window.h"



Window::Window()
{
    createGUI();
}
void Window::showMeCat(){

    QLabel * myImageLabel = new QLabel();
    QPixmap myImage("C:/Users/csheare/Documents/GitHub/gender_Qt/cat.jpg");
    myImageLabel->setPixmap(myImage);
    layout->addWidget(myImageLabel,5,0);
    this->show();
}

void Window::showMeDog(){

    QLabel * myImageLabel = new QLabel();
    QPixmap myImage("C:/Users/csheare/Documents/GitHub/gender_Qt/dog.png");
    myImageLabel->setPixmap(myImage);
    layout->addWidget(myImageLabel,5,0);
    this->show();
}

void Window::showMeBoth(){
    QWidget *temp = new QWidget();
    QGridLayout *scrollLayout = new QGridLayout();
    QScrollArea * scrollArea = new QScrollArea();

    QLabel * myImageLabelCat = new QLabel();
    QPixmap myImageCat("C:/Users/csheare/Documents/GitHub/gender_Qt/cat.jpg");
    myImageLabelCat->setPixmap(myImageCat);
    scrollLayout->addWidget(myImageLabelCat,0,0);

    QLabel * myImageLabelDog = new QLabel();
    QPixmap myImageDog("C:/Users/csheare/Documents/GitHub/gender_Qt/dog.png");
    myImageLabelDog->setPixmap(myImageDog);
    scrollLayout->addWidget(myImageLabelDog,1,0);

    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(temp);
    temp->setLayout(scrollLayout);

    layout->addWidget(scrollArea,5,0);
    this->show();
}

void Window::createGUI()
{
    QLabel* myImageLabel = new QLabel();
    layout = new QGridLayout;

    //add name label
    QLabel *myNameLabel = new QLabel();
    QString name = "Name: ";
    myNameLabel->setText(name);
    layout->addWidget(myNameLabel,0,0);

    //add text box
    QTextEdit *te = new QTextEdit();
    layout->addWidget(te,1,0);


    //add Radio Buttons
    catButton = new QRadioButton("cat");
    dogButton = new QRadioButton("dog");
    bothButton = new QRadioButton("both");
    layout->addWidget(catButton,2,0);
    layout->addWidget(dogButton,3,0);
    layout->addWidget(bothButton,4,0);

    //connect button to images
    QObject::connect(catButton, SIGNAL(clicked()),this,SLOT(showMeCat()));
    QObject::connect(dogButton, SIGNAL(clicked()),this,SLOT(showMeDog()));
    QObject::connect(bothButton, SIGNAL(clicked()),this,SLOT(showMeBoth()));

    setWindowTitle(tr("Animals"));
    setLayout(layout);


}

