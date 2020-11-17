#pragma once
#include"diag.h"
#include"screen.h"
class view{
    protected:
        void printLine(char ch = '#') {
            string st;
            st.push_back(ch);
            For(i, 1, 60) Screen.print(st);
            Screen.print("\n");
        }
    public:
        virtual void display() = 0;
};