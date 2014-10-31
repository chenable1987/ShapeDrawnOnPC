#ifndef SHAPE_H
#define SHAPE_H
#include <QColor>

class Shape
{
public:
    Shape();
    virtual ~Shape();
    //Shape* create(QColor fillColor,QColor penColor,int penWidth);
    virtual void scale(float scalar);
    virtual void offset(float x, float y);
    virtual void draw();

protected:
    QColor fillColor;
    QColor penColor;
    int penWidth;
};

#endif // SHAPE_H
