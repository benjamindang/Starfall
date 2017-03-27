#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem* parent = 0);
    void add();
    int get_points();
private:
    int points;
};

#endif // SCORE_H
