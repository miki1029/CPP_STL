#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int _x=0, int _y=0) : x(_x), y(_y) {}

    // +
    const Point operator+(const Point& arg) const
    {
        Point pt;
        pt.x = this->x + arg.x;
        pt.y = this->y + arg.y;

        return pt;
    }

    // ++
    const Point& operator++()   // prefix
    {
        ++x;
        ++y;
        return *this;
    }
    const Point operator++(int) // postfix
    {
        Point pt(x, y);
        ++x;
        ++y;
        return pt;
    }

    // --
    const Point& operator--()   // prefix
    {
        --x;
        --y;
        return *this;
    }
    const Point operator--(int) // postfix
    {
        Point pt(x, y);
        --x;
        --y;
        return pt;
    }

    // ==
    bool operator==(const Point& arg) const
    {
        return x == arg.x && y == arg.y;
    }
    // !=
    bool operator!=(const Point& arg) const
    {
        return !(*this == arg);
    }

    void Print() const { cout << x << ',' << y << endl; }
};

int main()
{
    Point p1(2, 3), p2(5, 5), p3(2, 3);

    if(p1 != p2)
        cout << "p1 != p2" << endl;
    if(p1 == p3)
        cout << "p1 == p3" << endl;

    return 0;
}