#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

struct Point {
    double x, y;

    double distanceTo(const Point& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }

     // Define equality operator to compare Point objects
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

std::vector<Point> nearestNeighbor(std::vector<Point> deliveryPoints) {
    std::vector<Point> route;
    route.push_back(deliveryPoints[0]); // Start from the first point
    deliveryPoints.erase(deliveryPoints.begin()); // Remove the starting point

    while (!deliveryPoints.empty()) {
        Point currentLocation = route.back();
        double minDistance = std::numeric_limits<double>::max();
        Point nearestPoint;

        for (const Point& point : deliveryPoints) {
            double distance = currentLocation.distanceTo(point);
            if (distance < minDistance) {
                minDistance = distance;
                nearestPoint = point;
            }
        }

        route.push_back(nearestPoint);
        deliveryPoints.erase(std::find(deliveryPoints.begin(), deliveryPoints.end(), nearestPoint));
    }

    // Return to the starting point to complete the cycle
    route.push_back(route.front());

    return route;
}

int main() {
    std::vector<Point> deliveryPoints = {
        {0, 0},
        {1, 2},
        {3, 1},
        {4, 3},
        {2, 4}
    };

    std::vector<Point> route = nearestNeighbor(deliveryPoints);

    std::cout << "Optimal Route:" << std::endl;
    for (const Point& point : route) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }

    return 0;
}

/*
Given a list of delivery points, 
design a program that uses a vehicle routing algorithm (e.g., Nearest Neighbor) to find the shortest route for a delivery truck to visit all points and return to the starting point. 
*/

/*
In this example, 
the nearestNeighbor function iterates 
through the delivery points, selecting the nearest unvisited 
point to the current location and adding it to the route. 
Once all points have been visited, the function returns to the starting point to complete the cycle.

https://leanne.godbolt.org/z/vjM639h9x
*/