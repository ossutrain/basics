#include <iostream>
#include <stack>
using namespace std;

void move(stack<int> &a, stack<int> &b){
	int x = a.top();
	a.pop();
	b.push(x);
}
void toh(stack<int> &a, stack<int> &b, stack<int> &c, int k){
	if(k!=0){
		toh(a,c,b,k-1);
		move(a,b);
		toh(c,b,a,k-1);
	}
}
int main(){
	int n=32;
	stack<int> a;
	for(int i=n;i>=1;i--)
		a.push(i);
	stack<int> b;
	stack<int> c;
	toh(a,b,c,n);
	cout<<"A\n";
	while(!a.empty()){
		cout<<a.top()<<"  ";
		a.pop();
	}	
	cout<<'\n';
	cout<<"B\n";
	while(!b.empty()){
		cout<<b.top()<<"  ";
		b.pop();
	}
	cout<<'\n';
}
