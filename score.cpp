#include "score.h"
#include<QFont>

extern int globalscore;

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent){
    globalscore = 0;
    setPlainText(QString("Score: ") + QString::number(globalscore));
    QFont font("Times", 30, QFont::Cursive, true);
    setFont(font);
    setDefaultTextColor(Qt::yellow);
    setX(135);
    setY(500);
}

void Score::add(){
    globalscore++;
    setPlainText(QString("Score: ") + QString::number(globalscore));
}

