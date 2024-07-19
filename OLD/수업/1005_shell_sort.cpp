#include <iostream>

using namespace std;

int main() {
    int arr[1001]; // 입력을 받을 배열
    int n; // 배열 크기
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i]; // 입력 받기
    }

    int gap = n;

    while (gap > 1) {
        gap /= 2;

        // gap이 짝수일 경우 홀수로 만들어줌
        if ((gap % 2) == 0) {
            gap--;
        }

        // 삽입 정렬을 사용하여 각 부분 배열을 정렬
        for (int i = 0; i < n; i++) {
            for (int j = i + gap; j < n; j += gap) {
                int key = arr[j];
                int k = j - gap; // 현재 부분 배열 내에서 정렬할 원소의 인덱스

                // 현재 부분 배열을 삽입 정렬하는 과정
                // key보다 큰 값을 갖는 원소를 오른쪽으로 이동
                for (; k >= 0 && arr[k] > key; k -= gap) {
                    arr[k + gap] = arr[k];
                }
                arr[k + gap] = key; // key 값을 올바른 위치에 삽입
            }
        }
    }

    // 정렬된 배열 출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
