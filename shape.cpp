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

void Shape::scale(float scalar)
{}

void Shape::offset(float a, float b)
{}

void Shape::draw()
{}
