#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;


int MaxPairwiseProduct(const vector<int>& numbers) {
	int n = numbers.size();
	int64_t max1, max2;
	if(n<2)
		return -1;
	if(numbers[0]>numbers[1]){
		max1 = numbers[0];
		max2 = numbers[1];
	}
	else{
		max1 = numbers[1];
		max2 = numbers[0];
	}
	for(int i=2;i<n;i++){
		if(numbers[i]>max1){
			max2 = max1;
			max1 = numbers[i];
		}
		else{
			if(numbers[i] > max2){ 
			/*max1 >= numbers[i] > max2 for clarity but to reduce comparison operations removing
			 max1 >= numbers[i] since it is obvious from previous if condition*/
			max2 = numbers[i];
			}
		}
	}
	return max1*max2;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
