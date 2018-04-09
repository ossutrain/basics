#include <iostream>
#include <string>
using namespace std;

/*int main(){
	string s;
	cin>>s;
	int i=s.size()-1;
	int multiple = 1;
	int number = 0;
	int maxpos = 0;
	bool isnegative = (s[0] == '-');
	if(isnegative){
		maxpos = 1;
	}	
	while(i>=maxpos){
		int digit = s[i] - '0';
		number += digit*multiple;
		multiple *= 10;
		i--;
	}
	if(isnegative){
		number *= -1;
	}
	cout<<"number is "<<number<<'\n';
	return 0;
}*/

int main(){
	int s;
	cin>>s;
	string number;
	bool isnegative = (s<0);
	if(isnegative){
		s *= -1;//make it positive
	}
	while(s){
		char digit = '0' + s%10;
		s = s/10;
		number = digit + number;
	}
	if(isnegative){
		number = '-' + number;
	}
	cout<<"number is "<<number<<'\n';
	return 0;
}
