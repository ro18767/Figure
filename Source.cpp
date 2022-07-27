#include "Figure.h"


int main() {

  cout << line << endl;
  cout << "Testing Point:" << endl;
  cout << line << endl;
  {
    Point figure(1, 2);
    cout << figure.get_perimetr() << endl;
    cout << figure.get_area() << endl;
    figure.draw();
  }
  cout << line << endl;
  cout << "Testing Line:" << endl;
  cout << line << endl;
  {
    Line figure(1, 2, 3, 4);
    cout << figure.get_perimetr() << endl;
    cout << figure.get_area() << endl;
    figure.draw();
  }
  cout << line << endl;
  cout << "Testing Ellipse:" << endl;
  cout << line << endl;
  {
    Ellipse figure(1, 2);
    cout << figure.get_perimetr() << endl;
    cout << figure.get_area() << endl;
    figure.draw();
  }
  cout << line << endl;
  cout << "Testing Сircle:" << endl;
  cout << line << endl;
  {
    Сircle figure(1);
    cout << figure.get_perimetr() << endl;
    cout << figure.get_area() << endl;
    figure.draw();
  }
  cout << line << endl;
  cout << "Testing Polygon:" << endl;
  cout << line << endl;
  {
    Polygon figure({ {0,0},{1,0},{0,1} });
    cout << figure.get_perimetr() << endl;
    cout << figure.get_area() << endl;
    figure.draw();
  }
  cout << line << endl;
  cout << "Testing Triangle:" << endl;
  cout << line << endl;
  {
    Triangle figure({ {0,0},{1,0},{0,1} });
    cout << figure.get_perimetr() << endl;
    cout << figure.get_area() << endl;
    figure.draw();
  }
  cout << line << endl;
  cout << "Testing Quadrilateral:" << endl;
  cout << line << endl;

  {
    Quadrilateral figure({ {0,0},{1,0},{1,1},{0,1} });
    cout << figure.get_perimetr() << endl;
    cout << figure.get_area() << endl;
    figure.draw();

  }


  return 0;
}
