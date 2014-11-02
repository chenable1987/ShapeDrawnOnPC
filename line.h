#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape
{
public:
    Line(float pw, float sx, float sy, float ex, float ey):Shape(pw,sx,sy),endX(ex),endY(ey){};
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
