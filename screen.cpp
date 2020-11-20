#include "screen.h"
#include"diag.h"
#include"config.h"
void screen::Draw()
{
	//tab键补充颜色
	Forr(i, 0, height) {
		Forr(j, 0, width) {
			if (data[i * width + j] == '\t') {
				int j1 = min(((j / 8) + 1) * 8, width - 1);
				right(&data[i*width], j + 1, j1 - j - 1);
				For(k, j, j1 - 1) data[i * width + k] = WHITE;
			}
		}
	}

	if (!switchOver) {
		COORD pos = { 0, 0 };
		SetConsoleCursorPosition(hOutBuf, pos);
		WriteConsole(hOutBuf, data1, height* width, &bytes, NULL);
		SetConsoleCursorPosition(hOutBuf, pos);
		WriteConsole(hOutBuf, data2, s + 10, &bytes, NULL);

		Forr(i, 0, height) {
			WriteConsoleOutputAttribute(hOutBuf, &data[i * width], width, COORD{0,short(i)}, &bytes);
		}
		SetConsoleActiveScreenBuffer(hOutBuf);
		
	}
	else {
		COORD pos = { 0, 0 };

		SetConsoleCursorPosition(hOutput, pos);
		WriteConsole(hOutput, data1, height* width, &bytes, NULL);//擦除缓冲区

		SetConsoleCursorPosition(hOutput, pos);
		WriteConsole(hOutput, data2, s + 10, &bytes, NULL);//填入文字

		Forr(i, 0, height) {
			WriteConsoleOutputAttribute(hOutput, &data[i * width], width, COORD{0, short(i)}, &bytes);//填入颜色
		}
		SetConsoleActiveScreenBuffer(hOutput);
	}
	switchOver = !switchOver;
}

screen::screen()
{
	i = 0; j = 0;
	memset(data, 0, sizeof(data));
	memset(data1, 0, sizeof(data1));
	Forr(i, 0, height)
		data1[i * width + width - 1] = '\n';
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
	For(i, 0, s) data2[i] = 0;
	i = 0;
	j = 0;
	s = 0;
	memset(data, 0, sizeof(data));
	For(i, 0, height) For(j, 0, width) data[i * width + j] = WHITE;
	memset(data2, 0, sizeof(data2));
}

void screen::print(string st, SHORT coll)
{
	int n = st.length();
	Forr(k, 0, n) {
		if (st[k] == '\n') {
			i += 1; j = 0;
		}
		else { 
			if (st[k] == '\t') 
				data[i * width + (j++)] = '\t';
			else data[i * width + (j++)] = coll; 
		}
		data2[s++] = st[k];
	}
}

void screen::right(WORD a[], int x, int p)
{
	For(k, 1, p) {
		Down(i, width - 1, x + 1) {a[i] = a[i - 1];}
	}
}




screen Screen;