#include <iostream>
#include <cstdlib>
#include <string>

#include "closestPair.h"
#include "point.cpp"
#include "line.cpp"
#include "curve.cpp"
#include "color_rgb.cpp"

/*TO DO
 * - divide and conquer convex hull
 * - graphics (plan)
 *
 * - fix random points to stay within bounds
 *
 * DONE
 *  - both closest pair
 *  - brute convex hull
 *
 *  - github?
 */

using namespace std;

//dimensions for sdl plotter
const int ROW_MAX = 500;
const int COL_MAX = 1000;
//for axis
const int MARGIN = 50;

SDL_Plotter g(ROW_MAX, COL_MAX);
int *data;


//function prototypes
void plotData(int x, int y);
void RandomizeData(int x, int y);

int main(int argc, char* argv[]){
    curve crv;
    /*
    cout << "Brute Force:  " << bruteForceClosestPair(testPts) << endl;
    cout << "Div & Conquer: " << divideAndConquerClosestPair(testPts) << endl;
    */

    //adjust the coordinates of the axes based on the margin
    int adjustYAxis = ROW_MAX-(MARGIN+1);
    int adjustXAxis = COL_MAX-MARGIN;

    cout << adjustXAxis << " " << adjustYAxis << endl;

    //dynamically allocate the array for random data
    data = new int [adjustYAxis];

    for(int i =0; i < adjustYAxis; i++){
        data[i] = rand()%adjustYAxis;
    }

    while (!g.getQuit()) {
        //plot axes on screen
        crv.plotAxis(MARGIN, adjustXAxis, adjustYAxis, g);

        if (g.kbhit()) {
            switch (g.getKey()) {
                case 'R':
                    RandomizeData(adjustXAxis, adjustYAxis);
                    break;
                case 'X': g.setQuit(true);
                    break;
            }
        }
        plotData(adjustXAxis, adjustYAxis);
    }

    return 0;
}

//generate random points
void RandomizeData(int adjustXAxis, int adjustYAxis) {
    g.clear();
    for(int i = MARGIN; i < adjustYAxis; i++){
        data[i] = rand()%adjustYAxis;
    }
    plotData(adjustXAxis, adjustYAxis);
}

//main draw function, gets called over and over, as fast as possible
void plotData(int adjustXAxis, int adjustYAxis) {
    for(int i = MARGIN; i < adjustYAxis;i++){
        g.plotPixel(i,data[i],0,0,0);

        if(i + 1 < adjustYAxis) g.plotPixel(i+1,data[i],0,0,0);
        if(i - 1 >= 0) g.plotPixel(i-1,data[i],0,0,0);
        if(data[i] + 1 < adjustYAxis) g.plotPixel(i,data[i]+1,0,0,0);
        if(data[i] - 1 >= 0)g.plotPixel(i,data[i]-1,0,0,0);
    }
    g.update();
}