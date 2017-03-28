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
    QPixmap myImage(cat);
    myImageLabel->setPixmap(myImage);
    layout->addWidget(myImageLabel,5,0);
    this->show();
}

void Window::showMeDog(){

    QLabel * myImageLabel = new QLabel();
    QPixmap myImage(dog);
    myImageLabel->setPixmap(myImage);
    layout->addWidget(myImageLabel,5,0);
    this->show();
    //this->setGeometry(50,50,150,200);
}

void Window::showMeBoth(){
    QWidget *temp = new QWidget();
    QGridLayout *scrollLayout = new QGridLayout();
    QScrollArea * scrollArea = new QScrollArea();

    QLabel * myImageLabelCat = new QLabel();
    QPixmap myImageCat(cat);
    myImageLabelCat->setPixmap(myImageCat);
    scrollLayout->addWidget(myImageLabelCat,0,0);

    QLabel * myImageLabelDog = new QLabel();
    QPixmap myImageDog(dog);
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
    QLabel *myCatLabel = new QLabel();
    QString cat = "Cat Image Upload: ";
    myCatLabel->setText(cat);
    layout->addWidget(myCatLabel,0,0);

    QPushButton * button = new QPushButton("Cat Browse");
    connect(button, SIGNAL(clicked()),SLOT(browseCat()));
    layout->addWidget(button,0,1);

    QLabel *myNameLabel = new QLabel();
    QString dog = "Dog Image Upload: ";
    myNameLabel->setText(dog);
    layout->addWidget(myNameLabel,1,0);

    QPushButton * button2 = new QPushButton("Dog Browse");
    connect(button2, SIGNAL(clicked()), SLOT(browseDog()));
    layout->addWidget(button2,1,1);

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


void Window::browseCat()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);

    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
    cat = fileNames.at(0);
}
void Window::browseDog()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);

    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
    dog = fileNames.at(0);
}
