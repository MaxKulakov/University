#pragma once
#include"mult.h"
#include<iostream>
#include<cmath>
#include<limits.h>


using namespace std;

Set::Set()
{
	/*size = 0;
	head = new node;
	tail = new node;
	head->prev = nullptr;
	tail->next = nullptr;
	head->next = tail;
	tail->prev = head;*/
}

Set::~Set()
{

}

bool Set::del_node(int x)//удаление
{
	node *r = head;
	if (!x || (r->next == NULL && r->prev == NULL))
		return false;
	while (r)
	{
		if (r->inf == x)
		{
			node *r_prev = r->prev;
			node *r_next = r->next;
			if (r_prev)
				r_prev->next = r_next;
			if (r_next)
				r_next->prev = r_prev;
			delete r;
			return true;
		}
		r = r->next;
	}
}

bool Set::check(int value)
{
	node *r = head;
	while (r)
	{
		if (r->inf == value)
			return true;
		//cout << "eto est'";
		r = r->next;
	}
	return false;
}

bool Set::contains(int x, Set &a)
{
	node *pfa = a.head;
	while (pfa)
	{
		if (pfa->inf == x)
			return true;
		pfa = pfa->next;
	}
	return false;
}

bool Set::NotContains(int x, Set &a)
{
	node *pfa = a.head;
	while (pfa)
	{
		if (pfa->inf != x)
			return true;
		pfa = pfa->next;
	}
	return false;
}

void Set::sort()
{
	node *temp = head;
	while (temp->next)
	{
		if (temp->inf > temp->next->inf)
		{
			swap(temp->inf, temp->next->inf);
			temp = temp->next;
			sort();
		}
		else
			temp = temp->next;
	}
}

void Set::push(int value)//заполнение
{
	bool fl = false;
	node *h = head;
	node *t = tail;
	node *r = new node;
	//r->inf = value;
	r->next = NULL;
	if (!h && !t)
	{
		r->inf = value;
		r->prev = NULL;
		head = r;
	}
	else if (check(value))
	{
		cout << "already exists" << endl;
		return;
	}
	else
	{
		r->inf = value;
		t->next = r;
		r->prev = t;
	}
	tail = r;
}

void Set::print()
{
	node *p = head;
	while (p)
	{
		cout << p->inf << " ";
		p = p->next;
	}
}

void Set::print_reverse()
{
	node *ptr = tail;

	while (ptr)
	{
		cout << ptr->inf << "\n";
		ptr = ptr->prev;
	}
}

void Set::clear()
{
	while (head)
	{
		node *ptr = head;
		head = ptr->next;
		delete ptr;
	}
	tail = head;


}

void Set::intersection(Set &a, Set&b, Set &res)//Intersection of 2 Sets(Works)
{
	node *pfa = a.head;
	node *pfb = b.head;
	node *pfres = res.head;
	while (pfa && pfb)
	{
		if (pfa->inf == pfb->inf)
		{
			res.push(pfa->inf);
			pfa = pfa->next;
			pfb = pfb->next;
		}
		else if (pfa->inf < pfb->inf)
		{
			pfa = pfa->next;
		}
		else if (pfa->inf > pfb->inf)
		{
			pfb = pfb->next;
		}
		else
		{
			pfa = pfa->next;
			pfb = pfb->next;
		}
	}
}

void Set::Union(Set &a, Set &b, Set &res)//Union of 2 Sets(Works)
{
	//Set *res = new Set();
	node *pfa = a.head;
	node *pfb = b.head;
	while (pfa)
	{
		res.push(pfa->inf);
		//res->push(pfb->inf);
		pfa = pfa->next;
		//pfb = pfb->next;
	}
	while (pfb)
	{
		res.push(pfb->inf);
		pfb = pfb->next;
	}
}

//void Set::Difference(Set &a, Set &b, Set &res)
//{
//	Set tmp;
//	tmp.intersection(a, b, tmp);
//	node *temp = tmp.head;
//	node *pfa = a.head;
//	node *pfb = b.head;
//	int min = INT_MAX;
//	int max = INT_MIN;
//	while (pfa)
//	{
//		if (pfa->inf <= min)
//		{
//			min = pfa->inf;
//			pfa = pfa->next;
//		}
//		else if (pfa->inf >= max)
//		{
//			max = pfa->inf;
//			pfa = pfa->next;
//		}
//	}
//	int i = min;
//	Set c;
//	//node *pfc = c.head;
//	while (i <= max)
//	{
//		c.push(i);
//		i++;
//	}
//	node *pfc = c.head;
//	pfa = a.head;
//	while (pfc)
//	{
//		if (a.contains(pfc->inf, a) && b.NotContains(pfc->inf, b))
//		{
//			res.push(pfc->inf);
//			pfc = pfc->next;
//		}
//			pfc = pfc->next;
//	}
//	//res.print();
//	//c.print();
//}

void Set::Difference(Set &a, Set &b, Set &res)
{
	node *pfa = a.head;
	while (pfa)
	{
		res.push(pfa->inf);
		pfa = pfa->next;
	}
	Set tmp;
	tmp.intersection(a, b, tmp);
	node *temp = tmp.head;
	node *pfres = res.head;
	while (temp)
	{
		if (res.contains(temp->inf, res))
		{
			res.del_node(temp->inf);
			temp = temp->next;
		}
		else
		{
			temp = temp->next;
		}
	}
}

//void Set::Difference(Set &a, Set &b, Set &res)
//{
//	Set tmp;
//	tmp.intersection(a, b, tmp);
//	node *temp = tmp.head;
//	node *pfa = a.head;
//	Set tmp1;
//	node *temp1 = tmp1.head;
//	//node *pfb = b.head;
//	while (pfa)
//	{
//		tmp1.push(pfa->inf);
//		pfa = pfa->next;
//	}
//	temp = tmp.head;
//	temp1 = tmp1.head;
//	while (temp && temp1)
//	{
//		if (temp1->inf == temp->inf)
//		{
//			//res.push(temp1->inf);
//			temp1 = temp1->next;
//			temp = temp->next;
//		}
//		else
//		{
//			temp1 = temp1->next;
//
//			res.push(temp1->inf);
//		}
//		//temp1 = temp1 ->next;
//	}
//}


void List::push(Set* x) { //теперь сам список знает, где его голова и хвост, а остальным об этом знать не следует

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

}

List::List()
{
	head = NULL;
	tail = NULL;
}

List::~List()
{

}


int main()
{
	setlocale(LC_ALL, "rus");
	Set p1;
	Set p2;
	Set res;
	cout << "Введите количество элементов первого множества ";
	int n;
	cin >> n;
	cout << "введите количество элементов второго множенства ";
	int m;
	cin >> m;
	cout << "введите первое множество " << endl;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		p1.push(k);
	}
	p1.sort();
	cout << "введите второе множество " << endl;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		p2.push(k);
	}
	p2.sort();
	cout << endl;
	cout << "Объединение" << endl;
	res.Union(p1, p2, res);
	res.print();
	cout << endl;
	//p1.del_node(2);
	cout << "множества" << endl;
	p1.print();
	cout << endl;
	p2.print();
	cout << endl;
	Set res1;
	cout << "Пересечение" << endl;
	res1.intersection(p1, p2, res1);
	res1.print();
	cout << endl;
	Set res2;
	cout << "Разность" << endl;
	res2.Difference(p1, p2, res2);
	res2.print();
	cout << endl;
	cout << endl;
	system("pause");
}