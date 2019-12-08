#pragma once
struct Point
{
	float x;
	float y;

	Point(const Point& tmp) :x(tmp.x), y(tmp.y) {};
	Point(float x, float y) :x(x), y(y) {};
	Point() :x(0), y(0) {};
	Point operator+(const Point& rtmp) const
	{
		return Point(x + rtmp.x, y + rtmp.y);
	}
	Point operator-(const Point& rtmp) const
	{
		return Point(x - rtmp.x, y - rtmp.y);
	}
	Point operator*(const float& rtmp) const
	{
		return Point(x * rtmp, y * rtmp);
	}

	void operator+=(const Point& rtmp);
};

//----����
bool Collision(Point a, Point b, float range);
float Length(const Point& tmp);
Point normalize(const Point& tmp);
bool RectCollision(const RECT& rect1, const RECT& rect2);
bool PointAndRectCollision(const Point& pt, const RECT& rect);
//----����