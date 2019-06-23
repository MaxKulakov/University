#pragma once
#include<string>
#include<vector>
#include<list>
#include<time.h>


struct Time
{
	int hour;
	int min;
};

class Request //класс заявки
{
public:
	Request();
	Request(int from, int to, int hb, int mb, int he, int me);
	int getFrom(); //геттер для возврата пункта отправления
	int getTo(); //геттер для возврата пункта доставки
	int getHB(); //геттер для возврата часа начала выполнения
	int getMB(); //геттер для возврата минут начала выполнения
	int getHE(); //геттер для возврата часа окончания выполнения
	int getME(); //геттер для возврата минуты окончания выполнения
private:
	int from; //откуда
	int to; //куда
	Time tb; //время начала выполнеия
	Time te; //время конца выполнения
};

class Courier //класс курьер
{
public:
	Courier();
private:
};

class Office //класс филлиал фирмы
{
public:
	Office(int number); //конструктор 
	int getNumber(); //возврат номера офиса
	bool getStatus(); //проверка наличия курьера в офисе
	void setCourier(Courier c); //прикрепление курьера к офису в начале рабочего дня
private:
	std::vector<Courier> cour; //список курьеров в офисе
	int number; //номера офиса
	bool courAvailable; //доступность курьера
};

class Controller //класс диспетчер
{
public:
	Controller();
	int random(int mix, int max); //функция рандомизации параметров для моделирования
	void createRequest(Request request); //занесение заявки в общий список
	void Work(int n, int m, int gen); //метод выполняющий моделирование
	bool availableCour(int n, int from); //прверка наличия курьера в конкретном офисе
	void generate(int gen, int n, int i); //создание заявок в течение часа
	int getDim(); //возвращает размерность вектора заявок
	Request getRequest(int i); //возвращает конкретную заявку из  вектора
	int getTransfer();  //возвращает количество минут потраченных  на пустые переезды
	float getemptyTransfer(); //возвращает среднее время пустых переездов
	float getavgTime(); //возвращает среднее время выполнения заявки
private:
	float emptyTransfer = 0; //пустой переезд
	int emptyCount = 0; //количство пустых  переездов
	int avgCount = 0; //количество всех выполненых заявок не считая пустых переездов
	float avgTransfer = 0; //суммарное время всех выполненых заявок
	std::vector<Request> requests; //вектор всех заявок
	std::vector<Office> offices; //вектор всех офисов
};

