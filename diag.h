#ifndef _diag_
#define _diag_
#include <stdlib.h>
#include <windows.h>
#include<thread>
/*
头文件，各种常量和公共空间
*/
#include <conio.h>
#include<stdio.h>
#include<string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include<mmsystem.h>
#include<iostream>
#include<Windows.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
#define RED 0x04
#define GREEN 0x02
#define YELLOW 0x06
#define WHITE 0x07
#define BLACK 0x00
#define isPlant(x) ((x/10 == 1) || (x / 10 == 3))
#define isZombie(x) ((x/10 == 2))
#define Forr(i, l, r) for(int i = l; i < r; i++)
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)
#endif