#pragma once
#include"Color.h"
#include"Figure.h"
#include"Style.h"


class Circle : virtual public Figure, public Color, public Style
{
public:
	Circle(int x, int y, int radius);//конструктор обычного круга
	Circle(int x, int y, int radius, std::string color, std::string coloring);//конструктор примера круга
	Circle();
	int getX();//геттеры/сеттеры
	void setX(int x);
	int getY();
	void setY(int y);
	int getRadius();
	void setRadius(int radius);
	double getPerimeter();//вычисление перметра
	double getArea();//вычисление площади
	void print();
protected:
	int x;
	int y;
	int radius;
	double area;
	double perimeter;
};
