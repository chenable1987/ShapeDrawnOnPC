#include "shape.h"
//#include <iostream>
//using namespace std;

Shape::Shape(QColor fillColor, QColor penColor, float penWidth, float startX, float startY)
{
    this->fillColor=fillColor;
    this->penColor=penColor;
    this->penWidth=penWidth;
    this->startX=startX;
    this->startY=startY;
}

Shape::~Shape()
{}

QColor Shape::getFillColor()
{
    return fillColor;
}

QColor Shape::getPenColor()
{
    return penColor;
}

float Shape::getPenWidth()
{
    return penWidth;
}

float Shape::getStartX()
{
    return startX;
}

float Shape::getStartY()
{
    return startY;
}

void Shape::scale(float scalar)
{}

void Shape::offset(float a, float b)
{}

void Shape::draw()
{}
