/*
随机生成方块类SEED，和随机函数srand()
*/
#ifndef _rand_
#define _rand_
#include"diag.h"

clock_t start;

int random(){
	start = clock();
	srand((int)start);
	rand();
	return rand();
}

int random(int x){
	start = clock();
	srand((int)start);
	rand();
	return rand() % (x);
}
int random(int x, int seed){
	srand(seed);
	rand();
	return rand() % (x);
}
int randint(int l, int r){
    return l+ rand()%(r - l + 1);
}

#endif