#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Segment{
	int a;
	int b;
};

bool cmp(struct Segment x, struct Segment y){
	if(x.a<y.a)
		return 1;
	else if(x.a==y.a && x.b<y.b)
		return 1;
	else if(x.a==y.a && x.b>y.b)
		return 0;
	else
		return 0;
}

int main(){
	cout<<"number of segments\n";
	int n;
	std::cin >> n;
	std::vector<Segment> seglist(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin>>seglist[i].a>>seglist[i].b;
	}
	sort(seglist.begin(), seglist.end(),cmp);
	/*for (int i = 0; i < n; ++i)
	{
		cout<<seglist[i].a<<"  "<<seglist[i].b<<"\n";
	}*/

	list<Segment> finall;
	int curr_min = seglist[0].a;
	int curr_max = seglist[0].b;
	//finall.push_back(seglist[0]);
	for(int i=1;i<seglist.size();i++){//start comparison with 2nd element a value
		if(curr_max>=seglist[i].a){
			 curr_min = seglist[i].a;
		}
		else{
			struct Segment temp;
			temp.a = curr_min;
			temp.b = curr_max;
			finall.push_back(temp);
			curr_min = seglist[i].a;
			curr_max = seglist[i].b;
		}
	}
	struct Segment temp;
	temp.a = curr_min;
	temp.b = curr_max;
	finall.push_back(temp);
	cout<<"final list\n";
	for (list<Segment>::const_iterator ci = finall.begin(); ci != finall.end(); ++ci)
         cout<<ci->a<<ci->b<<'\n';
}
