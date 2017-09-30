#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

using namespace std;

int checkOneAway(string str1, string str2)
{
    if(abs(str1.length() - str2.length()) > 1)
        return 1;
    int len1 = str1.length();
    int len2 = str2.length();
    int i = 0, j = 0;
    int count = 0;
    while(i < len1 && j < len2)
    {
        if(str1[i] != str2[j])
        {
            if(count == 1)
                return 1;
            if(len1 > len2)
                i++;
            else if(len2 > len1)
                j++;
            else
            {
                i++;
                j++;
            }
            count++;
        }
        else
        {
            i++;
            j++;
        }
    }
    if (i < len1 || j < len2)
        count++;
    if(count == 1)
        return 0;
    else
        return 1;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << checkOneAway(str1, str2);
    return 0;
}
