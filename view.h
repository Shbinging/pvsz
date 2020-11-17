#pragma once
#include"diag.h"
class view{
    protected:
        void printLine(char ch = '#') {
            For(i, 1, 60) printf("%c", ch);
            printf("\n");
        }
    public:
        virtual void display() = 0;
};