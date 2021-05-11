#include <iostream>
#include <iomanip>
using namespace std;

class Point
{
    double _x, _y;
    int id;
public:
    static int tot;
    Point(double a, double b):_x(a), _y(b){ tot++, id = tot; }
    Point(Point& b){_x = b._x, _y = b._y; tot++, id = tot;}
    Point(int a){_x = _y = (double)a; tot++, id = tot;}
    Point(){ _x = _y = 0.0; tot++, id = tot;}
    ~Point(){}
    void show()const { cout << setprecision(16) << "Point[" << id << "] : (" << x() << ", " << y() << ")" << endl; }
    double x()const { return _x; }
    double y()const { return _y; }
    double x(double &b) { return _x = b; }
    double y(double &b) { return _y = b; }
    static void showSumOfPoint();
    double getX()const { return _x; };
    double getY()const { return _y; };
    double setX(double &b) { return _x = b; }
    double setY(double &b) { return _y = b; }
    bool isEqual(Point &b)const { return getX() == b.getX() && getY() == b.getY(); }
    Point& copy(Point &b){ x(b._x), y(b._y); return *this;}
    Point& inverse(){ double t(_x); _x = _y, _y = t; return *this; }
    Point& inverse(Point &b){ setPoint(b.getY(), b.getX()); return *this; }
    Point& setPoint(double a, double b)
    {
        setX(a);
        setY(b);
        return *this;
    }
};
int Point::tot=0;
void Point::showSumOfPoint(){ cout << "In total : " << tot << " points." << endl; }
void ShowPoint(const Point &b){ cout << setprecision(16) << "Point : (" << b.getX() << ", " << b.getY() << ")" << endl; }
void ShowPoint(const double &a, const double &b) { cout << setprecision(16) << "Point : (" << a << ", " << b << ")" << endl; }

int main()
{
    int l(0);
    char c;
    double a, b;
    Point p, q, pt[60];
    while(std::cin>>a>>c>>b)
    {
        if(a == b)
            p.copy(pt[l].setPoint(a, b));
        if(a > b)
            p.copy(pt[l].setPoint(a, b).inverse());
        if(a < b)
            p.inverse(pt[l].setPoint(a, b));
        if(a < 0)
            q.copy(p).inverse();
        if(b < 0)
            q.inverse(p).copy(pt[l]);
        pt[l++].show();
        p.show();
    }
    q.show();
    cout<<"==========gorgeous separator=========="<<endl;
    double x(0), y(0);
    for(int i = 0; i < l; i++)
        x += pt[i].x(), y -= pt[i].y();
    pt[l].x(y), pt[l].y(x);
    q.copy(pt[l]).show();
    for(int i = 0; i <= l; i++)
        pt[i].show();
    cout<<"==========gorgeous separator=========="<<endl;
    const Point const_point(3, 3);
    const_point.show();
    for(int i = 0; i <= l; i++)
    {
        if(const_point.isEqual(pt[i]))
        {
            ShowPoint(const_point);
            ShowPoint(const_point.x(), const_point.y());
            ShowPoint(Point(const_point.x(), const_point.y()));
        }
    }
    const_point.showSumOfPoint();
}
/*
1,2
3,3
2,1
*/
