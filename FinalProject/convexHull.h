/*
* Author: Michelle Aurora, Zee Dugar, Mark DeJarnett,
*         Elisa Gonzalez, Elissa Skinner
* Assignment Title: Final Project
* Assignment Description: This program implements
*         the convex hull functions. The  two ways are
*         brute force and divide & conquer.
* Due Date: 4/5/2019
* Date Created: 3/18/2019
* Date Last Modified: 3/22/2019
*/

#ifndef FINALPROJECT_CONVEXHULL_H
#define FINALPROJECT_CONVEXHULL_H

#include <cmath>
#include <vector>
#include <algorithm>

#include "point.h"

/*
 * description: finds the points belonging to the convex hull of a given set
 *      of points using a brute force algorithm
 * return: a vector of points
 * precondition: points contains at least 3 distinct points
 * postcondition: a vector of points containing the points in the convex hull
 *      is returned; the parameter, points, is unchanged after the function call
 *
*/
vector<point> *bruteForceConvexHull(vector<point> setOfPoints);


vector<point> *divideAndConquerConvexHull(vector<point> setOfPoints);


/*
 * description: determine if two points have the same x and y values
 * return: bool
 * precondition: points p1 and p2 exist and are valid
 * postcondition: returns if the x and y values of the two points are the same
 *
*/
bool operator==(point p1, point p2){
    return (p1.getY() == p2.getY() && p1.getX() == p2.getX());
}


#endif //FINALPROJECT_CONVEXHULL_H
