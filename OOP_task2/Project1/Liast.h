#pragma once
#include"Figure.h"

using namespace std;

struct node {

	Circle *inf;
	Square *inf1;
	Dot *inf2;
	node *next;

	node *prev;

};

class List {

private:

	node* head;

	node* tail;

public:

	List() { head = nullptr; tail = nullptr; }

	void push(Circle *x);
	void push(Square *z);
	void push(Dot *y);
	void print();


};