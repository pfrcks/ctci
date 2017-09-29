#include <iostream>

using namespace std;

int isUniqueTricky(string s)
{
   /* This method is only for alphabets. Utilizes the 32 bits
    * of an integer to store the occurence of a character */
    int bittrack=0;
    for(char & ch: s)
    {
        int shift = ch - 'a';
        if(bittrack & (1<<shift))
        {
            return 1;
        }
        bittrack += (1<<shift);
    }
    return 0;
}
int isUnique(string s)
{
    bool hash[256]={false};
    for(char & ch: s)
    {
        if(hash[ch]==true)
            return 1;
        hash[ch]=true;
    }
    return 0;
}
int main()
{
    string str;
    getline(cin, str);
    cout <<    isUniqueTricky(str);
    return 0;
}
