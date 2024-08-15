#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s, c;
vector<int> arr(1000005);

bool check(long long mid) {
    long long cnt = 0;
    for(int i = 0; i < s; i++) {
        cnt += arr[i] / mid;
    }
    return cnt >= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> c;

    long long total = 0;
    for(int i = 0; i < s; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    long long lo = 0;
    long long hi = 1e9 + 5;
    while(lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if(check(mid)) lo = mid;
        else hi = mid;
    }

    cout << total - lo * c << endl;

    return 0;
}