#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack{
    int top;
    public:
        int a[MAX];
        Stack() {top = -1;}
        bool push(int x);
        int pop();
        bool isEmpty();
};

bool Stack::push(int x){
    if(top>=MAX)
    {
        cout << "Stack overflow" << endl;
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

int Stack:: pop(){
    if(top < 0)
    {
        cout << "Stack underflow" << endl;
        return 0;
    }
    else
    {
        return a[top--];
    }
}

bool Stack::isEmpty()
{
    return (top<0);
}

