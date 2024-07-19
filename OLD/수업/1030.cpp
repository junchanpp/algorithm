#include <iostream>
#include <vector>

using namespace std;

typedef struct Point {
    double x;
    double y;
} Point;

Point make_point(int x, int y){
    Point point = {x, y};
    return point;
}

int N, M;  // N은 입력 받을 사람의 개수, M은 선택할 경찰의 개수
vector<Point> inputList;  // 사람 좌표 리스트
vector<Point> answerList;  // 경찰 좌표 리스트

// 두 점 간의 거리를 계산하는 함수 (제곱근을 제외한 거리의 제곱)
int distance(Point p1, Point p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(){
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        inputList.push_back(make_point(x, y));
    }

    for (int i = 0; i < M; i++){
        int maxDistance = 0;
        int maxIndex = 0;

        // 선택된 좌표들과의 거리를 계산하여 가장 먼 좌표 선택
        for (int j = 0; j < N; j++){
            int minDistance = 1000000001;

            // 이미 선택된 좌표들과의 거리 계산
            for (int k = 0; k < i; k++){
                int temp = distance(answerList[k], inputList[j]);
                if (temp < minDistance){
                    minDistance = temp;
                }
            }

            // 현재까지의 최대 거리보다 크면 갱신
            if (minDistance > maxDistance){
                maxDistance = minDistance;
                maxIndex = j;
            }
        }

        // 선택된 좌표를 answerList에 추가
        answerList.push_back(inputList[maxIndex]);
    }

    // 선택된 M개의 좌표 출력
    for (int i = 0; i < M; i++){
        cout << answerList[i].x << " " << answerList[i].y << endl;
    }

    return 0;
}
