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
	Tags(); // ����������� ������
	void Show(); // ���������� ���� �� ������
	void InitZero(); // ������������ ������ ������
	void Move(); // ������������ (����, ����, ����, �����)
	bool IsWin(); // �������� �� �������
};

