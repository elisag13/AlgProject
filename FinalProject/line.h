#ifndef FINALPROJECT_LINE_H
#define FINALPROJECT_LINE_H

#include <iostream>

#include "point.h"

using namespace std;

class line {
public:
    line();
    line(point p1, point p2);
    virtual ~line();

    void display(ostream&  out);
    void draw(SDL_Plotter& g);

    void setP1(point p);
    void setP2(point p);
    void setColor(color_rgb c){color = c;}

    point getP1(){return p1;}
    point getP2(){return p2;}
    color_rgb getColor(){return color;}

    void nextColor();
    void resetColor();

private:
    point p1, p2;
    color_rgb color;
    bool slope(double& m);
    bool intercept(double& b);
    int currentColor;

};

#endif //FINALPROJECT_LINE_H
