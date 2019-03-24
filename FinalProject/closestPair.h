/*
* Author: Michelle Aurora, Zee Dugar, Mark DeJarnett,
*         Elisa Gonzalez, Elissa Skinner
* Assignment Title: Final Project
* Assignment Description: This program implements
*         the closet pair functions. The  two ways are
*         brute force and divide & conquer.
* Due Date: 4/5/2019
* Date Created: 3/18/2019
* Date Last Modified: 3/22/2019
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <float.h>

#include "point.h"

/*
* description: calculate the distance between two points
*              using the Euclidean formula (d = sqrt[(x2-x1)^2 + (y2-y1)^2])
* return: double
* precondition: the points p1 and p2 exist
* postcondition: return the distance between the points
*/
double calcDistance(point p1, point p2){
    return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}

/*
* description: find the closest pair of points in a given set
*              using the brute force method.
*
*             brute force goes through all points to find
*             all possible distances.
*
*             run time: 0(n^2)
* return: double
* precondition: the set contains valid points and
*               contains at a minimum 2 unique points.
* postcondition: return the closest pair of points
*/
double bruteForceClosestPair(vector<point> setOfPoints){
    //to check if duplicate
    bool duplicatePoint = false;

    //initialize distance (will be overwritten, DBL_MAX is temp)
    double minDistance = DBL_MAX;

    //go through all point in the set
    for(int i = 0; i < setOfPoints.size(); i++){
        //go through next adjacent point
        for(int j = i + 1; j < setOfPoints.size(); j++){

            //check for duplicates
            if(setOfPoints[i].getX() != setOfPoints[j].getX() ||
               setOfPoints[i].getY() != setOfPoints[j].getY()){

                //if not duplicate, then calculate the distance between the points
                if(!duplicatePoint){
                    minDistance = calcDistance(setOfPoints[i], setOfPoints[j]);
                    duplicatePoint = true;
                }

                //find minimum of all distances
                minDistance = min(minDistance, calcDistance(setOfPoints[i], setOfPoints[j]));
            }
        }
    }
    return minDistance;
}

/*
* description: compare the x values of two points
* return: bool
* precondition: the points p1 and p2 are valid
* postcondition: return if second point x is
*                greater than first point x value
*/
bool compareXValues(point p1, point p2){
    return (p2.getX() > p1.getX());
}

/*
* description: compare the y values of two points
* return: bool
* precondition: the points p1 and p2 are valid
* postcondition: return if second point y is
*                greater than first point y value
*/
bool compareYValues(point p1, point p2){
    return (p2.getY() > p1.getY());
}

/*
* description: find the closest pair of points in a given set
*              using the divide and conquer method.
*
*             divide and conquer splits the set of points in half,
*             checks the half with the current min distance
*             until smallest min distance is found.
*             recursive algorithm.
*
*             run time: 0(n logn)
* return: double
* precondition: the set contains valid points and
*               contains at a minimum 2 unique points.
* postcondition: return the closest pair of points
*/
double divideAndConquerClosestPair(vector<point> setOfPoints){
    //if no points in set (empty) then distance is 0
    //also if only 1 point then there's nothing to compare so distance is 0
    if(setOfPoints.size() == 0 ||
       setOfPoints.size() == 1){
        return 0;
    }

    //if there's only two points then compare them (base case)
    if(setOfPoints.size() == 2){
        return calcDistance(setOfPoints[0], setOfPoints[1]);
    }

    //if set has three points then D&C won't work, since it
    //will split into set of 1 point which will then return 0 (special case)
    else if(setOfPoints.size() == 3){
        //use brute force method to handle this case
        return bruteForceClosestPair(setOfPoints);
    }

    //sort by x values (least to greatest)
    sort(setOfPoints.begin(), setOfPoints.end(), compareXValues);

    //divide set into two parts
    int median = setOfPoints.size()/2;

    //sub sets based on median
    vector<point> halfOne(setOfPoints.begin(), setOfPoints.begin() + median);
    vector<point> halfTwo(setOfPoints.begin() + median, setOfPoints.end());

    //recursively to find distance
    double distanceOfOne = divideAndConquerClosestPair(halfOne);
    double distanceOfTwo = divideAndConquerClosestPair(halfTwo);

    //minimum of the two distances
    double minDist = min(distanceOfOne, distanceOfTwo);


    //to hold possible points that could have a min distance but are split
    vector<point> dividedPoints;

    //check if points that are divided into sub sets have a closest pair
    for(int i = 0; i < setOfPoints.size(); i++){

        //check how fair the point is from the median (the x value distance)
        if(abs(setOfPoints[i].getX() - setOfPoints[median].getX()) <= minDist){
            //if it is less than or equal to the current min distance
            //add it to the set
            dividedPoints.push_back(setOfPoints[i]);
        }
    }

    //the set of median possible points are sorted by y points now
    sort(dividedPoints.begin(), dividedPoints.end(), compareYValues);

    //go through all divided points
    for(int i = 0; i < dividedPoints.size(); i++){
        //compare to adjacent point
        //and if the y value difference is less than or equal to
        //the current min distance then calculate the new
        //min distance
        for(int j = i + 1; j < dividedPoints.size() &&
        dividedPoints[j].getY() - dividedPoints[i].getY() <= minDist; j++){
            //new min distance
            minDist = min(minDist, calcDistance(dividedPoints[i], dividedPoints[j]));
        }
    }
    return minDist;
}