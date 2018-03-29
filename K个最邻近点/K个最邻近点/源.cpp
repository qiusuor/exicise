#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};



class Solution {
public:
	/*
	* @param points: a list of points
	* @param origin: a point
	* @param k: An integer
	* @return: the k closest points
	*/
	struct distance
	{
		double dis;
		int x;
		int y;
	};
	bool cmp(const distance const a, const distance const b) {
		return a.dis < b.dis;
	}
	vector<Point> kClosest(vector<Point> points, Point origin, int k) {
		// write your code here
		
		distance *D=new distance[points.size()];
		for (int i=0;i<points.size();i++)
		{
			(D+i)->x=points[i].x;
			(D + i)->y = points[i].y;
			(D + i)->dis = sqrt((points[i].x - origin.x)*(points[i].x - origin.x) + (points[i].y - origin.y)*(points[i].y - origin.y));
		}
		sort(D, D + points.size(), this->cmp);
		cout << "DK";
	}
protected:
	
	
};

int main(void) {

	Point a(1, 2);
	Point b(4, 2);
	Point c(1, 7);

	vector<Point> t;
	t.push_back(a);
	t.push_back(b);
	t.push_back(c);
	Point s(3, 3);
	Solution jj;
	jj.kClosest(t, s, 2);

}