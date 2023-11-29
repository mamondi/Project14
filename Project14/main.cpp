#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

double calculateDistance(const Point& point1, const Point& point2) {
    double deltaX = point2.x - point1.x;
    double deltaY = point2.y - point1.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

int main() {
    Point pointA, pointB;

    std::cout << "Enter the coordinates of Point A (x y): ";
    std::cin >> pointA.x >> pointA.y;

    std::cout << "Enter the coordinates of Point B (x y): ";
    std::cin >> pointB.x >> pointB.y;

    double distance = calculateDistance(pointA, pointB);

    std::cout << "Distance between points: " << distance << std::endl;

    return 0;
}