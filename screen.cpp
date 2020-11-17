#include "screen.h"
#include"diag.h"
void screen::Draw()
{
	
	Forr(i, 0, height) {
		Forr(j, 0, width) {
			if (data[i][j] == '\t') {
				int j1 = ((j / 8) + 1) * 8;
				right(data[i], j + 1, j1 - j - 1);
				For(k, j, j1 - 1) data[i][k] = ' ';
			}
		}
	}
	
	/*
	int jj = 0;
	Forr(i, 0, height) {
		jj = 0;
		Forr(j, 0, width) {
			if (data[i][j] == '\t') {
				int j1 = ((j / 12) + 1) * 12;
				jj = j1 - 1;
				data[i][j] = ' ';
			}
			data1[i][jj] = data[i][j];
			jj++;
		}
	}*/
	//设置新的缓冲区为活动显示缓冲
	if (!switchOver) {
		for (int i = 0; i < height; i++) {
			coord.Y = i;
			WriteConsoleOutputCharacterA(hOutBuf, data[i], width, coord, &bytes);
		}
		SetConsoleActiveScreenBuffer(hOutBuf);
	}
	else {
		//设置新的缓冲区为活动显示缓冲
		for (int i = 0; i < height; i++) {
			coord.Y = i;
			WriteConsoleOutputCharacterA(hOutput, data[i], width, coord, &bytes);
		}
		SetConsoleActiveScreenBuffer(hOutput);
	}
	switchOver = !switchOver;
}

screen::screen()
{
	i = 0; j = 0;
	memset(data, 0, sizeof(data));
	hOutBuf = CreateConsoleScreenBuffer(
		GENERIC_WRITE,//定义进程可以往缓冲区写数据
		FILE_SHARE_WRITE,//定义缓冲区可共享写权限
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	hOutput = CreateConsoleScreenBuffer(
		GENERIC_WRITE,//定义进程可以往缓冲区写数据
		FILE_SHARE_WRITE,//定义缓冲区可共享写权限
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	//隐藏两个缓冲区的光标
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);
	SetConsoleCursorInfo(hOutBuf, &cci);
}

void screen::cls()
{
	i = 0;
	j = 0;
	For(i, 0, height) For(j, 0, width) data[i][j] = 0;
}

void screen::print(string st)
{
	int n = st.length();
	Forr(k, 0, n) {
		if (st[k] == '\n') {
			i += 1; j = 0;
		}
		else data[i][j++] = st[k];
	}
}

void screen::right(char a[], int x, int p)
{
	For(k, 1, p) {
		Down(i, width, x + 1) {a[i] = a[i - 1];}
	}
}




screen Screen;