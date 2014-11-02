#include "rectangle.h"

Rectangle::~Rectangle()
{

}
float Rectangle::getStartX()
{
    return startX;
}

float Rectangle::getStartY()
{
    return startY;
}

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
    Shape::startX=startX+a;
    Shape::startY=startY+b;
}

void Rectangle::draw()
{
   // cout<<"this is a rectangle w: "<<width<<" h: "<<height<<endl;
}
