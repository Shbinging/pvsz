#pragma once
#include<iostream>
#include "stdlib.h"
#include <Windows.h>
#include "diag.h"

const int width = 200;
const int height = 200;
class screen {
private:
	bool switchOver = false;
	int i, j;
	HANDLE hOutput, hOutBuf;//控制台屏幕缓冲区句柄
	COORD coord = { 0,0 };
	//双缓冲处理显示
	DWORD bytes = 0;
	char data[height*2][width*2], data1[height*2][width*2];

public:
	void Draw();
	screen();
	void cls();
	void print(string st);
	void right(char a[], int x, int p);
};

extern screen Screen;