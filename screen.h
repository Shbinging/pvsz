#pragma once
#include<iostream>
#include "stdlib.h"
#include <Windows.h>
#include "diag.h"
#include"config.h"

class screen {
private:
	bool switchOver = false;
	int i, j;
	HANDLE hOutput, hOutBuf;//控制台屏幕缓冲区句柄
	COORD coord = { 0,0 };
	//双缓冲处理显示
	DWORD bytes = 0;
	WORD data[height * width * 2];
	char data2[height * width], data1[height*width];;
	int s = 0;
public:
	void Draw();
	screen();
	void cls();
	void print(string st, SHORT coll = WHITE);
	void right(WORD a[], int x, int p);
};

extern screen Screen;