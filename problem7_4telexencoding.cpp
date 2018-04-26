#include <iostream>
#include <string>

using namespace std;

void insertins(string &s, int j, string c){
	cout<<c.size()<<'\n';
	for(int i=0; i<c.size(); i++,j++)
		s[j] = c[i];
	cout<<s.size()<<'\n';
}

int main(){
	string s = "Hi, how are you?";
	string QUESTION = "QUESTION MARK";
	string COMMA = "COMMA";
	int ssize = s.size();
	int nsize = 0;
	for(int i=0; i<ssize; i++){
		if(s[i] == ',')
			nsize += 5;
		else if(s[i] == '?')
			nsize += 13;
		else
			nsize += 1;
	}

	string buff(nsize-ssize,'X');

	s.append(buff); 
	cout<<s<<'\n';
	int j=nsize;
	for(int i=ssize-1;i>=0;i--){
		if(s[i]=='?'){
			j -=13;
			insertins(s,j,QUESTION);
		}
		else if(s[i] == ','){
			j -= 5;
			insertins(s,j,COMMA);
		}
		else{
			j -= 1;
			s[j] = s[i];
		}
	}
	cout<<s<<'\n';
}
