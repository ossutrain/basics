#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(vector<int> a){
	if(a.size()==0)
		return 1;
	if(a.size()==1)
		return 1;
	sort(a.begin(),a.end());
	int maxcount = 1;
	int currcount = 1;
	for(int i=1; i<a.size(); i++){
		if(a[i-1] == a[i]){
			currcount++;
		}
		else{
			if(maxcount < currcount){
				maxcount = currcount;
			}
		}
	}
	cout<<"mac count"<<maxcount<<"  "<<a.size()/2<<"\n";
	if(maxcount>(a.size()/2))
		return 1;
	else
		return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a) << '\n';
}
