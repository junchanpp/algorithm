#include <iostream>

using namespace std;

int N;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
	cin >> N;
	long long x = 0;
	long long y = 0;
	long long answer = 0;
	for(int i = 0; i < N; i++){
		long long a, b;
		cin >> a >> b;
		
        answer += a * y + b * x;

		x += a;
		y += b;
	}
	cout << answer << endl;
}