#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
    float ax = a.getX().toFloat();
    float ay = a.getY().toFloat();
    float bx = b.getX().toFloat();
    float by = b.getY().toFloat();
    float cx = c.getX().toFloat();
    float cy = c.getY().toFloat();

    float result = ((bx - ax)*(cy - ay) - (cx - ax)*(by - ay)) / 2.0f;
    if (result < 0)
        result = -result;
    return Fixed(result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    return (A1 > Fixed(0) && A2 > Fixed(0) && A3 > Fixed(0) && (A == (A1 + A2 + A3)));
}
