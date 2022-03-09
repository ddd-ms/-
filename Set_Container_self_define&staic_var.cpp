#include<iostream>
#include<set>
using namespace std;
class Point {
private:
	int x;
	int y;
public:
	int d;
	static int x0;
	static int y0;
	static void OriPoint(int x, int y) {
		 x0 = x;
		 y0 = y;
	}//静态函数写法
	Point(int x,int y):x(x),y(y){
		this->d = (x-x0) * (x-x0) + (y-y0) * (y-y0);
	}
	friend bool operator > (const Point& x,const Point& y);
	friend bool operator < (const Point& x,const Point& y);
	friend bool cmp(const Point& x,const Point& y);
	friend ostream& operator << (ostream& o,const Point& x);
};
bool operator>(const Point& x,const Point& y)
{
	return  x.d > y.d;
}
bool operator<(const Point& x,const Point& y)
{
	return x.d<y.d;
}
bool cmp(const Point& x,const Point& y) {
	return x < y;
}
ostream& operator<<(ostream& o,const Point& x)
{
	cout << "(" << x.x << "," << x.y << ")" << endl;
	return o;
}
int Point::x0 = 0;
int Point::y0 = 0;
int main() {
	int n;
	int x, y;
	cin >> n;
	while (n) {
		set<Point,bool (*) (const Point&,const Point&)> ps(cmp);
		cin >> x >> y;
		Point::OriPoint(x, y);
		for (int i = 0; i < n-1; i++) {
			cin >> x >> y;
			ps.emplace(Point(x, y));
		}
		cout << (*ps.begin()) << endl;
		cin >> n;
	}
	return 0;
}
