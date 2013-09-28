#ifndef RLABEL_H
#define RLABEL_H

#include <QLabel>


class QrLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(int degree READ getDegree WRITE setDegree) // свойство - градус поворота

    private:
        int degree; // текущий градус поворота
    public:
        QrLabel(QWidget *parent = 0);
        ~QrLabel();
        int  getDegree()
        {
            return degree;
        }
        void setDegree(int value)
        {
            rotor(value);
        }
        QPixmap rotation(int a, QPixmap pix);
public slots:
        void rotor(int a);
};
#endif // RLABEL_H
