#include "Figure.h"

Point::Point(double _x, double _y) : x{ _x }, y{ _y } {}
double Point::get_area() const {
  return 0;
}
double Point::get_perimetr() const {
  return 0;
}
void Point::draw() const {
  cout << "Point" << endl;
}
double Point::get_x() const {
  return x;
}
double Point::get_y() const {
  return y;
}
void Point::set_x(double _x) {
  x = _x;
}
void Point::set_y(double _y) {
  y = _y;
}

Line::Line(double _x1, double _y1, double _x2, double _y2) : line_start{ _x1,_y1 }, line_end{ _x2, _y2 } {}
double Line::get_area() const {
  return 0;
}
double Line::get_perimetr() const {
  return sqrt(pow(line_start.get_x() - line_end.get_x(), 2) + pow(line_start.get_y() - line_end.get_y(), 2));
}
void Line::draw() const {
  cout << "Line" << endl;
}

Ellipse::Ellipse(double _x_radius, double _y_radius) : radius{ _x_radius, _y_radius } {}
double Ellipse::get_area() const {
  return PI * radius.get_x() * radius.get_y();
}
double Ellipse::get_perimetr() const {
  double a = max(radius.get_x(), radius.get_y());
  double b = min(radius.get_x(), radius.get_y());
  return 4 * (PI * a * b + pow(a - b, 2)) / (a + b);
}
void Ellipse::draw() const {
  cout << "Ellipse" << endl;
}

Сircle::Сircle(double radius) : Ellipse(radius, radius) {}
double Сircle::get_area() const {
  return PI * pow(radius.get_x(), 2);
}
double Сircle::get_perimetr() const {
  return 2 * PI * radius.get_x();
}
void Сircle::draw() const {
  cout << "Ellipse" << endl;
}

Polygon::Polygon(initializer_list<Point> l) : Figure(), points{ l } {}
double Polygon::get_perimetr() const {
  double perimetr = 0;
  size_t size = points.size();
  for (size_t i = 0; i < size; i++)
  {
    perimetr += get_side_length(i);
  }
  return perimetr;
}
double Polygon::get_side_length(size_t i) const {
  i = i % points.size();
  size_t j = (i + 1) % points.size();
  return get_dist_between_points(points.at(i), points.at(j));
}
double Polygon::get_area() const {
  if (points.size() < 3) {
    return 0;
  }
  size_t triangle_count = points.size() - 2;
  double area = 0;
  for (size_t j = 0; j < triangle_count; j++) {
    double a = get_dist_between_points(points.at(0), points.at(j + 1));
    double b = get_dist_between_points(points.at(j + 1), points.at(j + 2));
    double c = get_dist_between_points(points.at(j + 2), points.at(0));
    double triangle_sime_perimetr = (a + b + c) / 2;
    cout << "get_area" << get_dist_between_points(points.at(j + 2), points.at(0)) << endl;

    double triangle_area = sqrt(triangle_sime_perimetr * (triangle_sime_perimetr - a) * (triangle_sime_perimetr - b) * (triangle_sime_perimetr - c));
    area += triangle_area;
  }
  return area;
}
void Polygon::draw() const {
  cout << "Polygon" << endl;
}
double Polygon::get_dist_between_points(const Point& p1, const Point& p2) const {
  return sqrt(pow(p1.get_x() - p2.get_x(), 2) + pow(p1.get_y() - p2.get_y(), 2));
}

Triangle::Triangle(Point _point, Point _point2, Point _point3) : Polygon{ _point, _point2, _point3 } {}
void Triangle::draw() const {
  cout << "Triangle" << endl;
}

Quadrilateral::Quadrilateral(Point _point, Point _point2, Point _point3, Point _point4) : Polygon{ _point, _point2, _point3, _point4 } {}
void Quadrilateral::draw() const {
  cout << "Quadrilateral" << endl;
}