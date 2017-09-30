#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

string urlify(string str, int len)
{
    int total_len = str.length()-1;
    for(int i = len-1 ; i >=0; i--)
    {
        if(str[i] != ' ')
        {
            str[total_len] = str[i];
            total_len--;
        }
        else
        {
            str[total_len--]='0';
            str[total_len--]='2';
            str[total_len--]='%';
        }

    }
    return str;
}

int main()
{
    string str;
    int len;
    getline(cin, str);
    cin >> len;
    cout << urlify(str, len);
}
