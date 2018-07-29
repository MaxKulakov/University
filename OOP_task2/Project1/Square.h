#pragma once
#include"Figure.h"
#include"Color.h"
#include"Style.h"

class Square : virtual public Figure, public Color, public Style
{
public:
	Square(int length);//конструктор квадрата
	Square(int length, std::string color, std::string coloring);//конструктор квадрата
	Square();
	int getLength();//геттеры/сеттеры
	void setLength(int length);
	int getPerimeter();//нахождение площади
	int getArea();//нахождение периметра
	void print();
private:
	int length;
	int width;
	int perimeter;
	int area;
};
