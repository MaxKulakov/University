#include"Figure.h"
#include"Color.h"
#include"Style.h"
#include"Circle.h"
#include"Dot.h"
#include"Square.h"
#include"Liast.h"
#include<list>
#include<iostream>

//РЕАЛИЗАЦИЯ МЕТОДОВ ВСЕХ КЛАССОВ

Figure::Figure()
{

}

Color::Color()
{

}

std::string Color::getColor()
{
	return color;
}

void Color::setColor(std::string color)
{
	this->color = color;
}

void Color::setColor()
{
	int k;
	std::cout << "Введите цвет\n 1 - черный \n 2 - белый\n 3 - красный\n";
	std::cin >> k;
	switch (k)
	{
	case 1:
		this->color = "черный";
		break;
	case 2:
		this->color = "белый";
		break;
	case 3:
		this->color = "красный";
		break;
	default:
		std::cout << "Неправильно введены данные\n";
		break;
	}
}

Style::Style()
{

}


std::string Style::getColoring()
{
	return coloring;
}

void Style::setColoring()
{
	int k;
	std::cout << "Введите цвет\n 1 - сплошной \n 2 - полосатый\n 3 - клетчатый\n";
	std::cin >> k;
	switch (k)
	{
	case 1:
		this->coloring = "сплошной";
		break;
	case 2:
		this->coloring = "полосатый";
		break;
	case 3:
		this->coloring = "клетчатый";
		break;
	default:
		std::cout << "Неправильно введены данные";
		break;
	}
}


void Style::setColoring(std::string coloring)
{
	this->coloring = coloring;
}

Decor::Decor()
{

}

Circle::Circle(int x, int y, int radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;
	std::cout << "Это круг с центром в точке " << x << "," << y << " и радиусом " << radius << std::endl;
}

Circle::Circle(int x, int y, int radius, std::string color, std::string coloring)
{
	this->x = x;
	this->y = y;
	this->radius = radius;
	this->color = color;
	this->coloring = coloring;
	std::cout << "Это " << color << " " << coloring << " круг с центром в точке " << x << "," << y << " и радиусом " << radius << std::endl;
}

Circle::Circle()
{

}

int Circle::getX()
{
	return x;
}

void Circle::setX(int x)
{
	this->x = x;
}

int Circle::getY()
{
	return y;
}

void Circle::setY(int y)
{
	this->y = y;
}

int Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(int radius)
{
	this->radius = radius;
}

double Circle::getPerimeter()
{
	int radius = this->radius;
	return 2 * 3.14 * radius;
}

double Circle::getArea()
{
	int radius = this->radius;
	return 3.14 * (radius * radius);
}

void Circle::print()
{
	std::cout << "Это " << this->color << " " << this->coloring << " круг с центром в точке " << this->x << "," << this->y << " и радиусом " << this->radius << std::endl;
}

Dot::Dot(int x, int y)
{
	this->x = x;
	this->y = y;
	std::cout << "Это точка с координатами " << x << "," << y << std::endl;
}

Dot::Dot(int x, int y, std::string color)
{
	this->x = x;
	this->y = y;
	this->color = color;
	std::cout << "Это " << color << " точка с координатами " << x << "," << y << std::endl;
}

Dot::Dot()
{

}

int Dot::getX()
{
	return x;
}

void Dot::setX(int x)
{
	this->x = x;
}

int Dot::getY()
{
	return y;
}

void Dot::setY(int y)
{
	this->y = y;
}

void Dot::print()
{
	std::cout << "Это " << this->color << " точка с координатами " << this->x << "," << this->y << std::endl;
}

Square::Square(int length)
{
	this->length = length;
	this->width = width;
	std::cout << "Это квадрат с стороной " << length << std::endl;
}

Square::Square(int length, std::string color, std::string coloring)
{
	this->length = length;
	this->width = width;
	this->color = color;
	this->coloring = coloring;
	std::cout << "Это " << coloring << " " << color << " квадрат с стороной " << length << std::endl;
}

Square::Square()
{

}

int Square::getLength()
{
	return length;
}

void Square::setLength(int length)
{
	this->length = length;
}
int Square::getPerimeter()
{
	int length = this->length;
	return (length + length) * 2;
}

int Square::getArea()
{
	int length = this->length;
	return length * length;
}

void Square::print()
{
	std::cout << "Это " << this->coloring << " " << this->color << " квадрат с стороной " << this->length << std::endl;  
}


void List::push(Circle *x)
{
		node *r = new node;
		
		r->inf = x;

		r->next = NULL;

		if (!head && !tail) {

			r->prev = NULL;

			head = r;

		}

		else {

			tail->next = r;

			r->prev = tail;

		}

		tail = r;
		r->inf1 = nullptr;
		r->inf2 = nullptr;
}

void List::push(Square *x)
{
	node *r = new node;

	r->inf1 = x;

	r->next = NULL;

	if (!head && !tail) {

		r->prev = NULL;

		head = r;

	}

	else {

		tail->next = r;

		r->prev = tail;

	}

	tail = r;
	r->inf = nullptr;
	r->inf2 = nullptr;
}

void List::push(Dot *x)
{
	node *r = new node;

	r->inf2 = x;

	r->next = NULL;

	if (!head && !tail) {

		r->prev = NULL;

		head = r;

	}

	else {

		tail->next = r;

		r->prev = tail;

	}

	tail = r;
	r->inf = nullptr;
	r->inf1 = nullptr;
}

void List::print()

{

	node *r = head;

	while (r != NULL) {
		if (r->inf != nullptr)
		{
			r->inf->print();
			cout << '\n';
			r = r->next;
		}
		else if (r->inf1 != nullptr)
		{
			r->inf1->print();
			cout << '\n';
			r = r->next;
		}
		else
		{
			r->inf2->print();
			cout << '\n';
			r = r->next;
		}
	}



}

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Доступеные варианты расцветок\n белый\n черный\n красный\n";
	std::cout << "Доступные варианты стиля(окраски фигyры)\n сплошной\n полосатый\n клетачатый\n";
	Circle *new1 = new Circle(0, 0, 4, "красный", "сплошной");
	Circle *new2 = new Circle(0, 0, 8, "белый","клетчатый");
	Dot *new3 = new Dot(4, 6, "черный");
	Square *new4 = new Square(4,"красный","сплошной");
	Circle *test = new Circle(0,0,2,"","");
	List *tmp = new List();
	tmp->push(new1);
	tmp->push(new2);
	tmp->push(new3);
	tmp->push(new4);
	cout << "Список\n";
	tmp->print();
	system("pause");
	return 0;
}