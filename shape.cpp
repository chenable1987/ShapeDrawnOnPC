#include "shape.h"

Shape::Shape(float pw, float sx, float sy)
{
    penWidth=pw;
    startX=sx;
    startY=sy;
}
Shape::~Shape()
{}

void Shape::scale(float scalar)
{}

void Shape::offset(float a, float b)
{}

void Shape::draw()
{}
