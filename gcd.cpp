#include <iostream>

int gcd_naive(int a, int b) {
	int curr_gcd = 1;
	while((a%2==0) && (b%2==0)){
		curr_gcd*=2;
		a=a/2;
		b=b/2;
	}
	for(int d=3; d<=a && d<=b; d+=2){
		if((a%d == 0) && (b%d ==0)){
			curr_gcd*=d;
			a=a/d;
			b=b/d;
		}
	}
	return curr_gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
