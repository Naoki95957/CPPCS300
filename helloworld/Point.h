#include <iostream>

class Point
{
    public:
        int x, y;
        Point(int x = 0, int y = 0);
        void setX(int x);
        void setY(int y);
        const int getX();
        const int getY();
        
        Point operator+(Point n);
};