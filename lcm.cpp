#include <iostream>

long long lcm(int a, int b){
	long long curr_lcm = 1;
	while((a%2==0) && (b%2 ==0)){
		curr_lcm*=2;
		a/=2;
		b/=2;
	}
	while(a%2==0){
		curr_lcm*=2;
		a/=2;
	}
	while(b%2==0){
		curr_lcm*=2;
		b/=2;
	}
	for(int d=3;d<=a || d<=b;d+=2){
		if((a%d==0) && (b%d==0)){
			curr_lcm*=d;
			a/=d;
			b/=d;
		}
		if(a%d==0){
			curr_lcm*=d;
			a/=d;
		}
		if(b%d==0){
			curr_lcm*=d;
			b/=d;
		}
	}
	return curr_lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
