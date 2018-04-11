#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    unordered_map<string, vector<string> > hashtable;
    vector<string> slist(10);
    slist[0] = "debitcard";
    slist[1] = "elvis";
    slist[2] = "silent";
    slist[3] = "badcredit";
    slist[4] = "lives";
    slist[5] = "freedom";
    slist[6] = "listen";
    slist[7] = "levis";
    slist[8] = "money";
    slist[9] = "selvi";

    for(int i=0;i<10;i++){
    	string sorted = slist[i];
    	sort(sorted.begin(), sorted.end());
    	hashtable[sorted].push_back(slist[i]);
    }

    unordered_map<string,vector<string> > :: iterator p;
    for(p = hashtable.begin(); p!=hashtable.end(); p++){
    	cout << p->first << " : ";
    	for(int j=0;j<p->second.size();j++)
    		cout<<p->second[j]<<"  ";
    	cout<<'\n';
    }
    	
 
}
