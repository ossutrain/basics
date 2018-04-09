#include <iostream>
#include <stack>

using std::stack;

stack<int> optimal_summands(int n) {
  stack<int> summands;
  int l = 1;
  while(n!=0){
    summands.push(l);
    n -= l;
    l++;
    if(n==0){
      break;
    }
    if(n<l){
      int x = summands.top();
      summands.pop();
      n += x;
    }
  }
  
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  stack<int> summands = optimal_summands(n);
  std::cout<<"size is " << summands.size() << '\n'<<"list : ";
  while(!summands.empty()){
    std::cout << summands.top() << ' ';
    summands.pop();
  }
  std::cout << '\n';
  /*for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }*/
}
