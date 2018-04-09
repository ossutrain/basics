#include <iostream>
#include <vector>

using std::vector;

struct item{
  int val;
  int wght;
};

bool cmp(struct item a, struct item b){
  return (a.val/a.wght)>(b.val/b.wght);
}

double get_optimal_value(int capacity, vector<item> itemlist) {
  double maxval = 0.0;
  sort(itemlist.begin(), itemlist.end(),cmp);

  /*for(int i=0; i<itemlist.size();i++){
    std::cout<<itemlist[i].val<<"  "<<itemlist[i].wght<<"\n";
  }*/

  int pos = 0;
  while(capacity>0){
    if(itemlist[pos].wght<=capacity){
      capacity -= itemlist[pos].wght;
      maxval += itemlist[pos].val;
      pos++;
    }
    else{
      maxval += itemlist[pos].val * capacity*1.0/itemlist[pos].wght;
      capacity = 0;
      pos++;
    }
  }

  return maxval;
}

int main() {
  int n;
  int capacity;
  std::cout<<"item count : weight"<<"\n";
  std::cin >> n >> capacity;
  vector<item> itemlist(n);
  //vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> itemlist[i].val >> itemlist[i].wght;
  }

  double optimal_value = get_optimal_value(capacity, itemlist);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
