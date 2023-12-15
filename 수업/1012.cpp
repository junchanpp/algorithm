#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// 모듈러 제곱을 계산하는 함수
long long modPow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

// Miller-Rabin 소수 판별 테스트 함수
bool millerRabinTest(long long n, long long a) {
    long long s = 0;
    long long d = n - 1;

    // n - 1 = 2^s * d로 분해
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    // a^d % n 계산
    long long x = modPow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;

    // a^(2^r * d) 계산
    for (long long r = 1; r < s; r++) {
        x = modPow(x, 2, n);
        if (x == n - 1)
            return false;
    }

    return true;
}

bool isPrime(long long n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;

    // Miller-Rabin 테스트에 사용할 숫자
    int testNumbers[3] = {2, 7, 61};

    // 각 테스트 숫자에 대해 Miller-Rabin 소수 판별 테스트 수행
    for (int i = 0; i < 3; i++) {
        long long a = testNumbers[i];
        if (millerRabinTest(n, a))
            return false;
    }
    return true;
}

int main() {
    // 입력 받을 숫자
    long long n;
    cin >> n;

    // 소수 여부 출력
    cout << isPrime(n) << endl;

    return 0;
}
