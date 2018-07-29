#pragma once
#include"Figure.h"
#include"Color.h"
#include"Style.h"

class Dot : virtual public Figure, public Color, public Style
{
public:
	Dot(int x, int y);//обычный конструктор
	Dot(int x, int y, std::string color);//конструктор точки из задания
	Dot();
	int getX();//геттеры/сеттеры
	void setX(int x);
	int getY();
	void setY(int y);
	void print();
private:
	int x;//координаты точка
	int y;
};
