#include "line.h"

//void Line::Line(float pw, float sx, float sy, float ex, float ey):Shape(pw,sx,sy),endX(ex),endY(ey)
//{}

Line::~Line()
{}
float Line::getStartX()
{
    return startX;
}

float Line::getStartY()
{
    return startY;
}

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
