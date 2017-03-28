#ifndef WINDOW_H
#define WINDOW_H

#include<QWidget>
#include<QRadioButton>
#include<QGridLayout>
class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
    QRadioButton * catButton;
    QRadioButton * dogButton;
    QRadioButton * bothButton;
    QGridLayout* layout;
    QString cat;
    QString dog;

public slots:
    void showMeCat();
    void showMeDog();
    void showMeBoth();
    void browseCat();
     void browseDog();

private:
    void createGUI();

};

#endif

//click image and sends to wiki(Qurl)
//open Qdialog to get user inputted url for an image, then load that image
//based on url
//have window to display interactive graphs use d3, openGL
