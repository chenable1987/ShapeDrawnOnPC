#include "line.h"

//void Line::Line(float pw, float sx, float sy, float ex, float ey):Shape(pw,sx,sy),endX(ex),endY(ey)
//{}

Line::~Line()
{}

void Line::scale(float scalar)
{
    endX=startX+(endX-startX)/scalar;
    endY=startY+(endY-endY)/scalar;
}

void Line::offset(float a, float b)
{
    Shape::startX=startX+a;
    Shape::startY=startY+b;
    endX=endX+a;
    endY=endY+b;
}

void Line::draw()
{}
