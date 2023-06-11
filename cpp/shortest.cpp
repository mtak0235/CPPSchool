#include <iostream>
#include <cmath>
#define RED "\033[31m"
#define BLACK "\033[37m"
#define RES "\033[36m"
using namespace std;
class Point
{
private:
    float x;
    float y;

public:
    Point(float x, float y) : x(x), y(y){};
    ~Point(){};
    Point(const Point &src)
    {
        if (this != &src)
        {
            x = src.x;
            y = src.y;
        }
    };
    Point &operator=(const Point &src)
    {
        if (this != &src)
        {
            x = src.x;
            y = src.y;
        }
        return *this;
    }
    float getX() const { return x; }
    float getY() const { return y; }
};

class Line
{
private:
    float a;
    float b;
    float c;

public:
    Line(float a, float b, float c) : a(a), b(b), c(c){};
    ~Line(){};
    Line(const Line &src)
    {
        if (this != &src)
        {
            a = src.a;
            b = src.b;
            c = src.c;
        }
    };
    Line &operator=(const Line &src)
    {
        if (this != &src)
        {
            a = src.a;
            b = src.b;
        }
        c = src.c;
        return *this;
    };
    float getDistance(const Point &point) const
    {
        return abs(a * point.getX() + b * point.getY() + c) / sqrt(pow(a, 2) + pow(b, 2));
    };
};

int main()
{
    float a, b, c;
    cout << RED << "ax + by + c = 0의 계수를 입력하세요\n"
         << BLACK;
    cin >> a >> b >> c;
    Line line(a, b, c);
    cout << RED << "한 점의 좌표(x, y)를 입력하세요\n"
         << BLACK;
    float x, y;
    cin >> x >> y;
    Point point(x, y);
    cout << RES << "한 점과 직선 사이의 거리: " << line.getDistance(point) << "\n"
         << BLACK;
}