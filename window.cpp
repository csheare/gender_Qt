
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
void Window::showMe(){

    QLabel * myImageLabel = new QLabel();
    QPixmap myImage;
    if(qb->currentText() == "cat"){
         myImage.load("C:/Users/csheare/Desktop/gender_Qt/cat.jpg");
    }
    else{
       myImage.load("C:/Users/csheare/Desktop/gender_Qt/dog.png");
    }

    myImageLabel->setPixmap(myImage);
    layout->addWidget(myImageLabel,4,0);
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
    //qe->placeholderText("Type your name here!");
    layout->addWidget(te,1,0);

    //Add animal combo box
    qb = new QComboBox();
    qb->insertItem(0,"cat");
    qb->insertItem(1,"dog");
    layout->addWidget(qb,2,0);

    //add button
    QPushButton *button = new QPushButton("Click for Animal Image");
    layout->addWidget(button,3,0);

    QObject::connect(button, SIGNAL(clicked()),this,SLOT(showMe()));

    setWindowTitle(tr("Animals"));
    setLayout(layout);


}

