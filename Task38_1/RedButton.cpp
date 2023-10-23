#include "RedButton.h"

RedButton::RedButton(QWidget *parent)
{
    setParent(parent);
    setToolTip("Стоп");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("up.png");
    mButtonDownPixmap = QPixmap("down.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &RedButton::setDown);
    connect(this, &QPushButton::clicked, this, &RedButton::sound);

}
void RedButton::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}
QSize RedButton::sizeHint() const
{
    return QSize(100, 100);
}
QSize RedButton::minimumSizeHint() const
{
    return sizeHint();
}
void RedButton::keyPressEvent(QKeyEvent* e)
{
    setDown();
    
}
void RedButton::setDown()
{
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &RedButton::setUp);
}
void RedButton::sound()
{
    auto* player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("click.mp3"));
    player->play();
}
void RedButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}
RedButton::~RedButton()
{}
