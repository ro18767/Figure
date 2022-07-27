#pragma once
#include <iostream>
#include <initializer_list>
#include <vector>
#include <math.h>
using namespace std;

constexpr double PI = 3.14;

constexpr char line[] = "--";

// =======================
class Figure {
public:
  virtual double get_area() const = 0;
  virtual double get_perimetr() const = 0;
  virtual void draw() const = 0;
};

class Point : public Figure {
protected:
  double x;// position
  double y;// position
public:
  Point(double _x, double _y);
  double get_area() const;
  double get_perimetr() const;
  void draw() const;
  double get_x() const;
  double get_y() const;
  void set_x(double _x);
  void set_y(double _y);
};

class Line : public Figure {
protected:
  Point line_start;
  Point line_end;
public:
  Line(double _x1, double _y1, double _x2, double _y2);
  double get_area() const;
  double get_perimetr() const;
  void draw() const;

};

class Ellipse : public Figure {
protected:
  Point radius;
public:
  Ellipse(double _x_radius, double _y_radius);
  double get_area() const;
  double get_perimetr() const;
  void draw() const;

};

class Сircle : public Ellipse {
public:
  Сircle(double radius);
  double get_area() const;
  double get_perimetr() const;
  void draw() const;
};

class Polygon : public Figure {
protected:
  double get_dist_between_points(const Point& p1, const Point& p2) const;
  vector<Point> points;
public:
  Polygon(initializer_list<Point> l);
  double get_perimetr() const;
  double get_side_length(size_t i) const;
  double get_area() const;
  void draw() const;
};

class Triangle : public Polygon {
public:
  Triangle(Point _point, Point _point2, Point _point3);
  void draw() const;
};

class Quadrilateral : public Polygon {
public:
  Quadrilateral(Point _point, Point _point2, Point _point3, Point _point4);
  void draw() const;
};
