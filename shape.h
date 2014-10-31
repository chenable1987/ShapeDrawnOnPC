#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    Shape(float pw=1,float sx=0, float sy=0);
    virtual ~Shape();
    virtual void scale(float scalar);
    virtual void offset(float a, float b);
    virtual void draw();

protected:
    float penWidth;
    float startX;
    float startY;
};

#endif // SHAPE_H
