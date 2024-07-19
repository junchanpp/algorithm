#include <iostream>
#include <vector>

using namespace std;

int main(){
    int K;
    cin >> K;
    vector<int> nums(100000001,1);
    nums[0] = 0;
    nums[1] = 0;
    for(int i = 2; i <= 10000;i++){
        if(!nums[i]){
            continue;
        }
        for(int j = i*i; j < nums.size(); j+=i){
            nums[j] = 0;
        }
    }

    int count = 1;
    for(int i = 1; i <= 100000000; i++){
        if(nums[i]){
            if(count++ == K){
                cout << i;
            }
        }
    }

}