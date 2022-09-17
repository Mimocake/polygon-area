#include <iostream>
#include <math.h>
using namespace std;

class Dot
{
private:
    double x;
    double y;
public:
    Dot(double X, double Y) : x(X), y(Y) {}
    friend double length(Dot dot1, Dot dot2)
    {
        return abs(sqrt(pow(dot2.x - dot1.x, 2) + pow(dot2.y - dot1.y, 2)));
    }
    double getx() { return x; }
    double gety() { return y; }
    friend ostream& operator << (ostream& c, Dot d);
};

ostream& operator << (ostream& c, Dot d)
{
    c << '(' << d.x << ", " << d.y << ')';
    return c;
}

class Line
{
private:
    Dot d1, d2;
public:
    Line(Dot D1, Dot D2) : d1(D1), d2(D2) {}
    friend Dot operator + (Line l1, Line l2)
    {
        return Dot(1, 1);
    }
};

class Triangle
{
private:
    Dot a, b, c;
public:
    Triangle(Dot A, Dot B, Dot C) : a(A), b(B), c(C) {}
    double area()
    {
        double p = (length(a, b) + length(b, c) + length(a, c)) / 2;
        double ar = p * (p - length(a, b)) * (p - length(b, c)) * (p - length(a, c));
        return sqrt(ar);
    }
};
 
class Polygon
{
    Dot* dots;
};

int main()
{
    Line l1(Dot(1, 1), Dot(2, 2));
    Line l2(Dot(3, 3), Dot(4, 4));
    cout << (l1 + l2);
}
