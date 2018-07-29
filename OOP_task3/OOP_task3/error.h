#pragma once
#include<string>
#include<iostream>

class Exception
{
public:
	Exception();
	Exception(std::string str);
	void getException(std::string str);

private:
	std::string str;

};

Exception::Exception()
{

}

Exception::Exception(std::string str)
{
	std::cout << str << std::endl;
}

void Exception::getException(std::string str)
{
	std::cout << str << std::endl;
}

class InputException : public virtual Exception
{
public:
	InputException(std::string str);
	void getInputException(std::string str);

private:
	std::string str;

};

InputException::InputException(std::string str)
{
	std::cout << str << std::endl;
}

void InputException::getInputException(std::string str)
{
	std::cout << str << std::endl;
}

class MemoryException : public virtual Exception
{
public:
	MemoryException(std::string str);
	void getException(std::string str);
private:
	std::string str;

};

MemoryException::MemoryException(std::string str)
{
	std::cout << str << std::endl;
}

void MemoryException::getException(std::string str)
{
	std::cout << str << std::endl;
}

