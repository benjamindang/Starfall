#include "score.h"
#include<QFont>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent){
    points = 0;
    setPlainText(QString("Score: ") + QString::number(points));
    QFont font("Times", 30, QFont::Cursive, true);
    setFont(font);
    setDefaultTextColor(Qt::yellow);
    setX(135);
    setY(500);
}

void Score::add(){
    points++;
    setPlainText(QString("Score: ") + QString::number(points));
}

int Score::get_points(){
    return points;
}
