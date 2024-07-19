#include <iostream>

using namespace std;

int* v = NULL;
int* sortedArr = NULL;

void swap(int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
void merge(int left, int right) {
    int middle = (left + right)/2;
    int i = left;
    int j = middle+1;
    int k = left;

    while(i <= middle && j <= right){
        if(v[i] > v[j]){
            sortedArr[k++] = v[j++];
        } else {
            sortedArr[k++] = v[i++];
        }
    }
    while(i<=middle){
        sortedArr[k++] = v[i++];
    }
    while(j<=right){
        sortedArr[k++] = v[j++];
    }
`
    for(int a = left ; a <= right; a++){
        v[a] = sortedArr[a];
    }
}

void sort(int left, int right) {
    if(left >= right)return;
    if(right - left == 1) {
        if(v[left] > v[right])swap(left,right);
        return;
    }
    int middle = (left + right)/2;
    sort(left, middle);
    sort(middle+1, right);

    merge(left, right);
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

    v = new int[n];
    sortedArr = new int[n];
	
    for(int i = 0 ; i < n;i++){
		cin >> v[i];
	}

    sort(0, n-1);
	
	for(int i = 0; i < n; i++){
		cout << v[i] << endl;
	}
}

