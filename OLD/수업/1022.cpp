#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void downHeap(vector<int>& arr, int root, int end) {
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;
    int maxChild = root;

    if (leftChild <= end && arr[leftChild] < arr[maxChild]) {
        maxChild = leftChild;
    }

    if (rightChild <= end && arr[rightChild] < arr[maxChild]) {
        maxChild = rightChild;
    }

    if (maxChild != root) {
        swap(arr[root], arr[maxChild]);
        downHeap(arr, maxChild, end);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    for (int i = (n / 2) - 1; i >= 0; --i) {
        downHeap(arr, i, n - 1);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    buildMaxHeap(arr);


    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);

        downHeap(arr, 0, i - 1);
    }
}

bool isAllAbove(vector<int>& arr, int minMoney) {
    int size = arr.size();
    for(int i = 0 ; i < size ; i++){
        if(arr[i] < minMoney){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    getline(cin, s);
    istringstream is(s);
    vector<int> v;
    string temp;
    int tempInt;
    while(is >> tempInt){
        v.push_back(tempInt);
    }
    int minMoney;
    scanf("%d", &minMoney);

    heapSort(v);

    int count = 0;
    while(!isAllAbove(v, minMoney)){
        int a = v.back();
        v.pop_back();
        int b = v.back();
        v.pop_back();
        
        v.push_back(a+b*2);
        heapSort(v);
        count++;
    }
    
    cout << count;

    return 0;
}
