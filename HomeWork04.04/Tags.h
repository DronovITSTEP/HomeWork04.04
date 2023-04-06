#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class Tags
{
	int index_zero;
	enum { LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 };
	const static int size = 16;
	int nums[size];

public:
	Tags(); // конструктор класса
	void Show(); // отобржение игры на экране
	void InitZero(); // отслеживание пустой клетки
	void Move(); // перестановка (верх, вних, лево, право)
	bool IsWin(); // проверка на выйгрыш
};

