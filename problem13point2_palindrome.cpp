#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    unordered_map<char, int> hashtable;
    string s="abcwabc";

    for(int i=0; i<s.size();i++)
    	++hashtable[s[i]];

    unordered_map<char, int> :: iterator p;
    int oddscount = 0;
    for(p = hashtable.begin(); p!=hashtable.end(); p++){
    	if(p->second%2==0)
            continue;
        else
            oddscount++;
    }
    if(oddscount<=1)
        cout<<"palindrome\n";
}
