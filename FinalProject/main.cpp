/*
* Author: Michelle Aurora, Zee Dugar, Mark DeJarnett,
*         Elisa Gonzalez, Elissa Skinner
* Assignment Title: Final Project
* Assignment Description: This program runs and shows the visualization of
*         the brute force closest pair and convex hull algorithms
*         and the divide & conquer closest pair and convex hull algorithms.
* Due Date: 4/5/2019
* Date Created: 3/18/2019
* Date Last Modified: 3/24/2019
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

#include "closestPair.h"
#include "point.cpp"
#include "line.cpp"
#include "curve.cpp"
#include "color_rgb.cpp"

/*TO DO
 * - divide and conquer convex hull
 * - graphics
 *      * need to slow down the bf closest pir graphics (press key C)
 *
 *
 * DONE
 *  - brute force closest pair
 *  - div and conquer closest pair
 *  - brute force convex hull
 *
 *  - github repo set up
 */

using namespace std;

//dimensions for sdl plotter
const int ROW_MAX = 500;
const int COL_MAX = 1000;
//for axis
const int MARGIN = 50;

int main(int argc, char* argv[]){
    //initialize plotter with dimensions
    SDL_Plotter g(ROW_MAX, COL_MAX);
    g.update();

    //points
    vector<point> setOfPoints;

    //adjust the coordinates of the axes based on the margin
    int adjustYAxis = ROW_MAX-(MARGIN+1);
    int adjustXAxis = COL_MAX-MARGIN;

    cout << adjustXAxis << " " << adjustYAxis << endl;

    while (!g.getQuit()) {
        //plot axes on screen
        //crv.plotAxis(MARGIN, adjustXAxis, adjustYAxis, g);

        if (g.kbhit()) {
            g.clear();
            setOfPoints.clear();

            srand(time(NULL));
            //randomize the points (30 currently for testing)
            for(int i = 0; i < 30; i++){
                int maxPtY = (rand() % adjustYAxis);
                int maxPtX = (rand() % adjustXAxis);

                //make a random point
                point pt(maxPtX, maxPtY);

                //add to set of points
                setOfPoints.push_back(pt);
            }

            switch (g.getKey()) {
                case 'C':
                    bruteForceClosestPair(g, setOfPoints);

                case 'P':
                    pair<point, point> pairOfPoints;
                    divideAndConquerClosestPair(g, setOfPoints, pairOfPoints);
            }
        }
    }

    return 0;
}