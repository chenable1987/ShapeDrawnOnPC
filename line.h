#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape
{
public:
    Line(QColor fillColor=Qt::red, QColor penColor=Qt::blue, float penWidth=1.0f, float startX=0 , float startY=0 , float endX=100, float endY=100);
    ~Line();
    float getStartX();
    float getStartY();
    float getEndX();
    float getEndY();
    void scale(float scalar);
    void offset(float a, float b);
    void draw();


private:
    float endX;
    float endY;
};

#endif // LINE_H
