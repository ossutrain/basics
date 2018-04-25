#include <iostream>
#include <random>
using namespace std;

void reservoir(int res[], int k, int i, int ival){
	int j = rand()%i;
	if(j<k)
		res[j] = ival;
}

int main(){
	srand (time(NULL));
	int k = 4;
	int res[k];
	int n = 1;
	cout<<"start stream \n";
	for(int i=0;i<k;i++,n++)
		cin>>res[i];
	int next;
	cin>>next;
	while(next!=100){
		reservoir(res,k,n,next);
		n++;
		cout<<"current res status \n";
		for(int i=0;i<k;i++)
			cout<<res[i]<<"  ";
		cout<<'\n';
		cin>>next;
	}
}
