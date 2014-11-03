#include "line.h"


Line::Line(QColor fillColor, QColor penColor, float penWidth, float startX , float startY , float endX, float endY):Shape(fillColor,penColor,penWidth,startX,startY)
{
    this->endX=endX;
    this->endY=endY;
};

Line::~Line()
{}

float Line::getEndX()
{
    return endX;
}

float Line::getEndY()
{
    return endY;
}

void Line::scale(float scalar)
{
    endX=startX+(endX-startX)/scalar;
    endY=startY+(endY-endY)/scalar;
}

void Line::offset(float a, float b)
{
    startX=startX+a;
    startY=startY+b;
    endX=endX+a;
    endY=endY+b;
}

void Line::draw()
{}
