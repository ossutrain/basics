#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxdiff = 0;
	int prevmin = a[0];
	for(int i=1;i<n;i++){
		if(a[i]<prevmin)
			prevmin = a[i];
		if((a[i]-prevmin)>maxdiff)
			maxdiff = a[i]-prevmin;
	}
	cout<<"max profit = "<<maxdiff<<'\n';
}
