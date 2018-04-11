#include <iostream>
using namespace std;

void merge(int a[], int b[], int asize, int bsize){
	//int *a = *aref;
	int j = bsize-1;
	while(j>=0){
		int i = asize-1;
		while(a[i] >= b[j] && i>=0){
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = b[j];
		asize++;
		j--;
	}
}

int main(){
	int a[10] = {1,2,3,7,9};
	int b[] = {0,5,6,8,9};
	merge(a,b,5,5);
	for(int k=0;k<10;k++)
		cout<<a[k]<<"  ";
	cout<<'\n';
}
