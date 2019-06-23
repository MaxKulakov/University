#include"Classes.h"
#include<vector>
#include<string>
#include<time.h>
#include<algorithm>
#include<Windows.h>

using namespace System::Collections::Generic;


Courier::Courier()
{

}

Request::Request(int from, int to, int hb, int mb, int he, int me) //конструктор с параметрами.
{
	this->from = from;
	this->to = to;
	this->tb.hour = hb;
	this->tb.min = mb;
	this->te.hour = he;
	this->te.min = me;
}

Request::Request()
{

}

int Request::getFrom()
{
	return this->from;
}

int Request::getTo()
{
	return this->to;
}

int Request::getHB()
{
	return tb.hour;
}

int Request::getMB()
{
	return tb.min;
}

int Request::getHE()
{
	return te.hour;
}

int Request::getME()
{
	return te.min;
}

Office::Office(int num) //конструктор с параметрами
{
	this->number = num;
}

int Office::getNumber()
{
	return number;
}

bool Office::getStatus()
{
	return courAvailable;
}

void Office::setCourier(Courier c)
{
	cour.push_back(c);
}

Controller::Controller()
{

}

void Controller::createRequest(Request request)
{
	requests.push_back(request);
}

int Controller::random(int min, int max)
{
	max++;
	return abs(rand() % (max - min)) + min;
}

bool Controller::availableCour(int n, int from) //проверка наличия курьера в офисе
{
	for (int i = 0; i < n; i++)
	{
		if ((from == offices[i].getNumber()) && (offices[i].getStatus()))
		{
			return true;
		}
	}
	return false;
}

void Controller::generate(int gen, int n, int i) //генерация заявок в течение часа
{
	for (int j = 0; j < 60; j += gen)
	{
		int from = random(1, n);
		int to = random(1, n);
		if (to == from)
		{
			to = random(3, n);
		}
		int pr = random(1, 2);
		int vel = random(-5, 30);
		std::string status = "in queue";
		if (availableCour(n, from))
		{
			avgCount++;
			avgTransfer = avgTransfer + (j - (j + vel));
			int hb = i;
			int mb = j;
			if (mb >= 60)
			{
				hb++;
				mb = mb - 60;
			}
			int me = j + vel + 10;
			int he = i;
			if (me >= 60)
			{
				he++;
				me = me - 60;
			}
			Request req(from, to, hb, mb, he, me);
			createRequest(req);
		}
		int hb = i;
		int mb = j;
		int me = j + vel + 10 + 10;
		int he = i;
		emptyTransfer += 10;
		emptyCount++;
		if (me >= 60)
		{
			he++;
			me = me - 60;
		}
		Request req(from, to, hb, mb, he, me);
		createRequest(req);
	}
}

void Controller::Work(int n, int m, int gen)//моделирование ситуации
{
	for (int i = 0; i < n; i++)
	{
		Office a(i);
		offices.push_back(a);
	}
	if ((n == m) || (n > m))
	{
		for (int i = 0; i < m; i++)
		{
			Courier c;
			offices[i].setCourier(c);
		}
	}
	else
	{
		switch (n)
		{
		case 3:
		{
			switch (m)
			{
			case 4:
			{
				Courier c1;
				Courier c2;
				Courier c3;
				Courier c4;
				offices[0].setCourier(c1);
				offices[0].setCourier(c2);
				offices[1].setCourier(c3);
				offices[2].setCourier(c4);
				break;
			}
			case 5:
			{
				Courier c1;
				Courier c2;
				Courier c3;
				Courier c4;
				Courier c5;
				offices[0].setCourier(c1);
				offices[0].setCourier(c2);
				offices[1].setCourier(c3);
				offices[2].setCourier(c4);
				offices[2].setCourier(c5);
				break;
			}
			}
		}
		case 4:
		{
			Courier c1;
			Courier c2;
			Courier c3;
			Courier c4;
			Courier c5;
			offices[0].setCourier(c1);
			offices[0].setCourier(c2);
			offices[1].setCourier(c3);
			offices[2].setCourier(c4);
			offices[3].setCourier(c5);
			break;
		}
		default:
			break;
		}
	}
	for (int i = 0; i < 600; i += 30)
	{
		if (i < 60)
		{
			int h = 9;
			generate(gen, n, h);
		}
		else if (i >= 60 && i <= 120)
		{
			int h = 10;
			generate(gen, n, h);
		}
		else if (i > 120 && i <= 180)
		{
			int h = 11;
			generate(gen, n, h);
		}
		else if (i > 180 && i <= 240)
		{
			int h = 12;
			generate(gen, n, h);
		}
		else if (i > 240 && i <= 300)
		{
			int h = 13;
			generate(gen, n, h);
		}
		else if (i > 300 && i <= 360)
		{
			int h = 14;
			generate(gen, n, h);
		}
		else if (i > 360 && i <= 420)
		{
			int h = 15;
			generate(gen, n, h);
		}
		else if (i > 420 && i <= 480)
		{
			int h = 16;
			generate(gen, n, h);
		}
		else if (i > 480 && i <= 540)
		{
			int h = 17;
			generate(gen, n, h);
		}
		else if (i > 540 && i < 600)
		{
			int h = 18;
			generate(gen, n, h);
		}
	}
}

int Controller::getDim()
{
	return requests.size();
}

Request Controller::getRequest(int i)
{
	return requests[i];
}

int Controller::getTransfer()
{
	return emptyTransfer;
}

float Controller::getavgTime()
{
	return abs(round((avgTransfer / avgCount) * 10) / 10);
}

float Controller::getemptyTransfer()
{
	return emptyTransfer / emptyCount;
}

