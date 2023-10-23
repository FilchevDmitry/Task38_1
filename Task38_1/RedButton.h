#pragma once
#include<iostream>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QVBoxLayout>
#include<QPushButton>
#include<QPixmap>
#include<QPainter>
#include<QPaintEvent>
#include<QSlider>
#include<QObject>
#include<QTimer>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/qsoundeffect.h>

class RedButton : public QPushButton
{
    Q_OBJECT;

public:
    RedButton() = default;
    RedButton(QWidget *parent);
    void paintEvent(QPaintEvent* e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const  override;
    void keyPressEvent(QKeyEvent* e) override;
    ~RedButton();

private slots:
    void setUp();
    void setDown();
    void sound();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown=false;

};
