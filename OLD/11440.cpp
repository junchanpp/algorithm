#include <iostream>
#include <map>

using namespace std;

long long solve(long long, map<long long, long long> &);

int main(){
    long long n;
    cin >> n;
    map<long long, long long> memo;
    cout << (solve(n, memo) * solve(n + 1, memo))%1000000007;
    // cout << solve(n, memo);
}

long long solve(long long n, map<long long, long long> &memo){
    if (n == 1 || n == 2){
        return 1;
    }
    if (n == 0){
        return 0;
    }
    if (memo.find(n) != memo.end()){
        return (memo.find(n))->second;
    }

    if (n % 2 == 1){
        long long half = solve((n + 1) / 2, memo);
        long long halfMinousOne = solve((n + 1) /2 - 1, memo);
        long long ans = (half * half + halfMinousOne * halfMinousOne)%1000000007;
        memo.insert(make_pair(n, ans));
        return ans;
    } else{
        long long half = solve(n / 2, memo);
        long long halfMinousOne = solve((n / 2) - 1, memo);
        long long halfPlusOne = solve(n / 2 + 1, memo);
        long long ans = (half * halfPlusOne + halfMinousOne* half)%1000000007;
        memo.insert(make_pair(n, ans));
        return ans;
    }
}
