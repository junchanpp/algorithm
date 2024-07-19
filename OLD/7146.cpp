#include <iostream>
using namespace std;

int V = 999, E = 1501;
int a = 0, b = 1;

int main() {
	cin.tie(0);
    cout.tie(0);
	ios::sync_with_stdio(0);

	cout << V << ' ' << E << '\n';
	for (int e = 0; e < E; e++) {

		cout << a << ' ' << b << '\n';
        b++;
		if(b >100){
            b = 0;
            a++;
        }
        if(a==b){
            b++;
        }
	}
}