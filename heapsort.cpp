#include <iostream>
#include <vector>
using namespace std;
void swap(int &x, int &y){
	//cout<<"swapping "<<x<<" and "<<y<<"\n";
	int temp;
	temp = x;
	x = y;
	y = temp;
}
void heapify(vector<int> &a,int heapsize, int i){
	int lchild = 2*i+1;
	int rchild = 2*i+2;
	int largest = i;
	if(lchild<=heapsize && a[i]<a[lchild])
		largest = lchild;
	if(rchild<=heapsize && a[largest]<a[rchild])
		largest = rchild;
	if(a[largest]!=a[i]){
		swap(a[i],a[largest]);
		heapify(a,heapsize,largest);
	}
}

void buildheap(vector<int> &a, int heapsize){
	//cout<<"heapsize is "<<heapsize<<'\n';
	for(int i=(int)(heapsize/2); i>=0;i--){
		//cout<<"heapify at "<<i<<'\n';
		heapify(a,heapsize,i);
	}
}

void heapsort(vector<int> &a){
	int heapsize =  a.size()-1;
	buildheap(a,heapsize);
	while(heapsize>0){//heapsize = 0 is single entry heap and heance sorted
		swap(a[0],a[heapsize]);
		heapsize -= 1;
		heapify(a,heapsize,0);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	heapsort(a);
	cout<<"\nprint heap\n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	cout<<"\n";
}
