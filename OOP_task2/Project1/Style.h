#pragma once
#include"Decor.h"


class Style : public Decor
{
public:
	Style();
	std::string getColoring();//геттеры/сеттеры
	void setColoring(std::string coloring);
	void setColoring();
protected:
	std::string coloring;//тип окрашивания(сплошной, полосатый, клетчатый)

};
