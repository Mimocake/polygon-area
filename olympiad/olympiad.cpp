#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Dot
{
private:
    double x;
    double y;
public:
    Dot() : x(0), y(0) {}
    Dot(double X, double Y) : x(X), y(Y) {}
    friend double length(Dot dot1, Dot dot2)
    {
        return abs(sqrt(pow(dot2.x - dot1.x, 2) + pow(dot2.y - dot1.y, 2)));
    }
    double getx() { return x; }
    double gety() { return y; }
    friend ostream& operator << (ostream& c, Dot d)
    {
        c << '(' << d.x << ", " << d.y << ')';
        return c;
    }
    friend istream& operator >> (istream& c, Dot& d)
    {
        c >> d.x >> d.y;
        return c;
    }
};

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
private:
    vector<Dot> dots;
public:
    Polygon(vector<Dot>& d) : dots(d) {}
    void info()
    {
        cout << "Number of vertex: " << dots.size();
        cout << "\nDots:\n";
        for (int i = 0; i < dots.size(); i++)
        {
            cout << dots[i] << endl;
        }
    }
    double area()
    {
        double ar = 0;
        for (int i = 2; i < dots.size(); i++)
        {
            ar += Triangle(dots[0], dots[i - 1], dots[i]).area();
        }
        return ar;
    }
};

int main()
{
    int x;
    cin >> x;
    vector<Dot> dots(x);
    for (int i = 0; i < x; i++)
    {
        cin >> dots[i];
    }
    Polygon p(dots);
    p.info();
    cout << p.area();
}
