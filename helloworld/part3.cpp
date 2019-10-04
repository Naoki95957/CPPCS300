#include <iostream>
#include "Point.cpp"

class part3
{
    public:
        static int exc2()
        {
            Point p1;
            Point p2(2);
            Point p3(2, 3);
            std::cout << p1.getX() << std::endl;
            p2.setX(4);
            std::cout << p2.getX() << std::endl;
            p3.setY(10);
            std::cout << p3.getY() << std::endl;
            return 0;
        }
        static int exc4()
        {
            Point *p1 = new Point();
            Point *p2 = new Point(2);
            Point *p3 = new Point(2, 3);
            std::cout << (*p1).getX() << std::endl;
            p2->setX(4);
            std::cout << (*p2).getX() << std::endl;
            p3->setY(10);
            std::cout << (*p3).getY() << std::endl;
            delete p1, p2, p3;
            return 0;
        }
        static int exc5()
        {
            Point p1(2, 10);
            Point p2(3, 4);
            Point p3 = p1 + p2;
            std::cout << p3.getX() << " " << p3.getY() << std::endl;
            return 0;
        }
};