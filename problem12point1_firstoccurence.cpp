#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search_recursive(const vector<int> &a, int left, int right, int x) {
  //base condition
  if(left > right)
    return left;
  //int mid = (int)(left+right)/2;
  int mid = left + (int)(right-left)/2;

  if(x <= a[mid])//less than condition
    return binary_search_recursive(a,left,mid-1,x);
  else//greater than condition
    return binary_search_recursive(a,mid+1,right,x);  
}

int binary_search_iterative(const vector<int> &a, int left, int right, int x) {
  int mid;
  while(left<=right){
    mid = (left + right)/2;
    if(x<=a[mid])
      right = mid-1;
    else
      left = mid+1;
  }
  return left;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  cout<<"search :";
  int x;
  cin>>x;
  int left = 0, right = (int)a.size()-1;
  int pos = binary_search_iterative(a,left,right, x);
  cout <<pos<< '\n';
  if(a[pos]== x)
    cout <<pos<< '\n';
  else
    cout<<"not found\n";
}
