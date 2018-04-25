#include <iostream>
#include <random>
using namespace std;

void swaps(int *a, int *b){
	cout<<"swapping "<<*a<<" with "<<*b<<'\n';
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void randsubset(int arr[], int n, int k){
	for(int i=0;i<k;i++){
		int pos = rand() % (n-i);
		int pick = i+pos;
		swaps(&arr[i],&arr[pick]);
	}
}

int main(){
	/* initialize random seed: */
  	srand (time(NULL));
	int n=10;
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i] = rand() % 100;
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"  ";
	cout<<'\n';
	int k = 5;
	randsubset(arr,n,k);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"  ";
}
