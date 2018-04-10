#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search(const vector<int> &a, int left, int right, int x) {
  //base condition
  if(left > right)
    return -1;
  //int mid = (int)(left+right)/2;
  int mid = left + (int)(right-left)/2;
  if(x == a[mid])//equal condition
    return mid;
  else if(x < a[mid])//less than condition
    return binary_search(a,left,mid-1,x);
  else//greater than condition
    return binary_search(a,mid+1,right,x);  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    int left = 0, right = (int)a.size()-1;
    //cout<<"searching for "<<b[i]<<'\n';
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a,left,right, b[i]) << ' ';
  }
  cout << '\n';
}
