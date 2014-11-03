#include "rectangle.h"

Rectangle::Rectangle(QColor fillColor, QColor penColor, float penWidth, float startX, float startY, float width,float height):Shape(fillColor,penColor,penWidth,startX,startY)
{
    this->width=width;
    this->height=height;
}

Rectangle::~Rectangle()
{}

float Rectangle::getWidth()
{
    return width;
}

float Rectangle::getHeight()
{
    return height;
}

void Rectangle::scale(float scalar)
{
    width=width/scalar;
    height=height/scalar;
}

void Rectangle::offset(float a, float b)
{
    startX=startX+a;
    startY=startY+b;
}

void Rectangle::draw()
{}
