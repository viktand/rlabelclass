#include "rlabel.h"
#include <QSize>
#include <QPainter>
#include <math.h>

#define PI 3.14159265

QPixmap *mem_pix;


QrLabel::QrLabel(QWidget *parent) : QLabel(parent)
{
}


QrLabel::~QrLabel()
{
}

void QrLabel::rotor(int a)
{
    degree=a;
    if (mem_pix==0) mem_pix = new QPixmap(*this->pixmap());
    QPixmap p(rotation(a, *mem_pix));
    QSize sz;
    QRect rc;
    QPoint pn;
    rc=this->geometry();
    pn.setX(rc.x()+rc.width()/2);
    pn.setY(rc.y()+rc.height()/2);
    sz=p.size();
    rc.setWidth(sz.width());
    rc.setHeight(sz.height());
    this->setGeometry(rc);
    this->setPixmap(p);
}

QPixmap QrLabel::rotation(int a, QPixmap pix)
{
    double g=a*PI/180;
    QSize sz=pix.size();
    QPixmap canv_pix(sz*2);
    canv_pix.fill(Qt::transparent); // залить пустотой
    // центр холста
    int x=sz.width();
    int y=sz.height();
    QPainter p(&canv_pix);
    p.translate(x,y);
    p.rotate(a);
    p.translate(-x,-y);
    p.drawPixmap(x/2,y/2, pix);
    p.end();
    int h=x*fabs(sin(g))+ y*fabs(cos(g));
    int w=x*fabs(cos(g))+ y*fabs(sin(g));
    x=x-w/2;
    y=y-h/2;
    pix=canv_pix.copy(x, y, w, h);
    return pix;
}
