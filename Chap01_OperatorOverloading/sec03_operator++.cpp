#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int _x=0, int _y=0) : x(_x), y(_y) {}

    const Point operator+(const Point& arg) const
    {
        Point pt;
        pt.x = this->x + arg.x;
        pt.y = this->y + arg.y;

        return pt;
    }
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
    /*
    const Point operator++(int) // postfix removing duplication
    {
        Point tmp = *this;
        ++*this;
        return tmp;
    }*/
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
    /*
    const Point operator--(int) // postfix removing duplication
    {
        Point tmp = *this;
        --*this;
        return tmp;
    }*/

    void Print() const { cout << x << ',' << y << endl; }
};

int main()
{
    Point p1(2, 3), p2(2, 3);
    Point result;

    // ++
    result = ++p1;
    p1.Print();
    result.Print();

    result = p2++;
    p2.Print();
    result.Print();
    cout << endl;

    // --
    result = --p1;
    p1.Print();
    result.Print();

    result = p2--;
    p2.Print();
    result.Print();

    return 0;
}