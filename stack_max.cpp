#include <iostream>
#include <stack>
using namespace std;

typedef int T;
struct entry
{
	T data;
	T max;
};

int main(){
	stack<struct entry*> stk;
	T x = 0;
	while(x!=1000){
		cin>>x;
		struct entry *node = new entry;
		node->data = x;
		if(stk.empty()){
			node->max = x;
		}
		else{
			struct entry *y = stk.top();
			if(x>y->max){
				node->max = x;
			}
			else{
				node->max = y->max;
			}
		}
		stk.push(node);
	}

	while(!stk.empty()){
		struct entry *n = stk.top();
		cout<<n->data<<" "<<n->max<<'\n';
		stk.pop();
	}
	cout<<'\n';
}
