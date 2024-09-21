#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(double a, double b, char op) {
    if (op == '+') return a + b == 24;
    if (op == '-') return a - b == 24;
    if (op == '*') return a * b == 24;
    if (op == '/') return b != 0 && a / b == 24;
    return false;
}

double calc(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return b != 0 ? a / b : 1e9;
    return 0;
}

int a, b, c, d;

bool isPossible(vector<int> nums) {
    char ops[] = {'+', '-', '*', '/'};

    do{
        for (char op1 : ops) {
            for (char op2 : ops) {
                for (char op3 : ops) {
                    int a = nums[0], b = nums[1], c = nums[2], d = nums[3];
                    double res1 = calc(calc(a,b,op1),calc(c,d,op3), op2);
                    double res2 = calc(calc(calc(a,b,op1),c,op2),d,op3);
                    double res3 = calc(a,calc(b,calc(c,d,op3),op2),op1);
                    double res4 = calc(calc(a,calc(b,c,op2),op1),d,op3);
                    double res5 = calc(a,calc(calc(b,c,op2),d,op3), op1);
                    
                    if (abs(res1 - 24) < 1e-6 || abs(res2 - 24) < 1e-6 || abs(res3 - 24) < 1e-6 ||
                        abs(res4 - 24) < 1e-6 || abs(res5 - 24) < 1e-6){
                            return true;
                        }
                }
            }
        }
    }while(next_permutation(nums.begin(),nums.end()));
    

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> nums(4);
        for (int i = 0; i < 4; ++i) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        if (isPossible(nums)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
            
    }

    return 0;
}
