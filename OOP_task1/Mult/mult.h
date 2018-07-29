	#pragma once
class Set
{
public:
	Set();
	~Set();
	bool check(int value);
	void push(int value);
	void print();
	void print_reverse();
	void clear();
	void sort();
	void intersection(Set &a, Set &b, Set &res);
	void Union(Set &a, Set &b, Set &res);
	void Difference(Set &a, Set &b, Set &res);
	bool del_node(int x);
	bool contains(int x, Set &a);
	bool NotContains(int x, Set &a);

protected:
	struct node
	{
		int inf;
		node *next;
		node *prev;
		//node(int value, node *n, node *p) :inf(value), next(n), prev(p) {}
	};

	node *head;
	node *tail;
	int size;

};

struct node
{
	Set *inf;
	node *prev;
	node *next;
};

class List
{
private:
	node *head;
	node *tail;

public:
	List();
	~List();
	void push(Set* x);
	void print();
};