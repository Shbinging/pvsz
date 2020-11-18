/*
随机生成方块类SEED，和随机函数srand()
*/
#ifndef _rand_
#define _rand_
#include"diag.h"



int random();
int random(int x);
int random(int x, int seed);
int randint(int l, int r);
#endif