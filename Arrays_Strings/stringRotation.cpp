#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string str1, str2, str3;
    cin >> str1 >> str2;
    str3 = str1 + str1;
    if(str3.find(str2) != std::string::npos)
        cout << 0;
    else
        cout << 1;
}
