#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(int x);

int arr[505] = {0,};

int keyGroups[505] = {0,};

int storeValue[505] = {0,};
int n;

int main() {
	scanf("%d", &n);
	
    vector<int> keyList;
	for(int i = 0 ; i < n ; i++){
        register int key, value;
		scanf("%d %d", &key, &value);
        keyGroups[key] = value;
        keyList.push_back(key);
	}
    
    sort(keyList.begin(),keyList.end());

    for(int i = 0; i < n; i++){
        arr[i] = keyGroups[keyList[i]];
    }
	
	int ans = 1;
	for(int i = 0 ; i< n;i++){
		ans = max(ans,lis(i));
	}
	printf("%d", n-ans);
}


int lis(int x){
	if(x >= n)return 1;
	if(storeValue[x] != 0)return storeValue[x];
	
	int sumMax = 1;//자기자신 
	for(int i = x+1; i< n; i++){
		int sum1 = 1;
		if(arr[i] > arr[x]){
			sum1+=lis(i);
			sumMax = max(sumMax, sum1);
		}
	}
	storeValue[x] = sumMax;
	return storeValue[x];
}