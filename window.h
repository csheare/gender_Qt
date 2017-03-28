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

public slots:
    void showMeCat();
    void showMeDog();
    void showMeBoth();

private:
    void createGUI();

};

#endif

//click image and sends to wiki(Qurl)
//vertical scroll window
//create a text editor
//image editor with scrolls, two images with scroll
//set geometry, do something with this
//open Qdialog to get user inputted url for an image, then load that image
//based on url
//change drop down to radio button, if click both then add both
//have window to display interactive graphs use d3, openGL
