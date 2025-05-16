#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(2, 2);
    Point p2(20, 1);
    Point p3(0, 0);
    Point p4(5, 5);

    std::cout << "p1 üçgenin içinde mi? " << (bsp(a, b, c, p1) ? "Evet" : "Hayır") << std::endl;
    std::cout << "p2 üçgenin içinde mi? " << (bsp(a, b, c, p2) ? "Evet" : "Hayır") << std::endl;
    std::cout << "p3 üçgenin içinde mi? " << (bsp(a, b, c, p3) ? "Evet" : "Hayır") << std::endl;
    std::cout << "p4 üçgenin içinde mi? " << (bsp(a, b, c, p4) ? "Evet" : "Hayır") << std::endl;

    return 0;
}
