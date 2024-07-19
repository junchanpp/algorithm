#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

typedef struct Point{
	double x;
	double y;
}Point;

Point* point = NULL;
int n;

bool compare(Point a, Point b){
	return a.x < b.x;
}
bool compareSub(Point a, Point b){
	return a.y < b.y;
}

double clossestPair(int left, int right);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    cin >> n;
    cin.ignore();
	
	point = new Point[n];
	
	for(int i = 0; i < n; i++){//입력을 위한 처리
        string temp; 
        getline(cin, temp);
        double x = stod(temp.substr(0,temp.find(", ")));
        double y = stod(temp.substr(temp.find(", ")+1));
		point[i].x = x;
        point[i].y = y;
	}
	
	sort(point, point+n, compare);//x를 기준으로 정렬
	
	double clossest = clossestPair(0,n-1);//최단거리 구하기

	cout << ((int)(sqrt(clossest)*1000000))/1000000 << "." << ((int)(sqrt(clossest)*1000000))%1000000;//소수점 처리 후 출력
}

double areaCalc(Point a, Point b){// 두 점 사이의 거리를 구하는 메서드
	double x = a.x - b.x;
	double y = a.y - b.y;
	return x*x + y*y;
}

double clossestPair(int left, int right){//범위안에서 가장 작은 거리 구하는 메서드
	if(right-left == 1){//2개의 요소만 있을 경우
		return areaCalc(point[left],point[right]);
	}
	if(right-left == 2){//3개의 요소만 있을 경우
		return min(areaCalc(point[left],point[left+1]),min(areaCalc(point[left],point[left+2]),areaCalc(point[left+1],point[left+2])));
	}
	
	int middle = (left+right)/2;
	
	double leftMinDistance = clossestPair(left, middle);//왼쪽 사이드에서 가장 작은 거리 구하기
	double rightMinDistance = clossestPair(middle+1,right);//오른쪽 사이드에서 가장 작은 거리 구하기
	
	double minDistance = min(leftMinDistance, rightMinDistance);//둘 중 작은 거리를 minDistance에 저장
	
	int line1X = point[middle].x; //왼쪽 사이드의 가장 오른쪽 점의 x
	int line2X = point[middle+1].x;//왼쪽 사이드의 가장 왼쪽 점의 x
	
	vector<Point> subPair;
	subPair.reserve(n);
	
	for(int i = left ; i <= middle ; i++){//후보군 추가
		int tempX = point[i].x - line1X;
		if(tempX*tempX < minDistance){
			subPair.push_back(point[i]);
		}
	}
	for(int i = middle+1 ; i <= right ; i++){//후보군 추가
		int tempX = point[i].x - line2X;
		if(tempX*tempX < minDistance){
			subPair.push_back(point[i]);
		}
	}

	sort(subPair.begin(),subPair.end(),compareSub);//y를 기준으로 정렬
	
	int size= subPair.size();
	for(int i = 0 ; i < size; i++){
		for(int j = i+1; j < size; j++){
			if(subPair[j].y - subPair[i].y >= minDistance) break;//y의 범위가 minDistance를 넘어가면 굳이 더 구하지 않음.
			else minDistance = min(minDistance, areaCalc(subPair[i],subPair[j]));//최소거리 재설정
		}
	}
	return minDistance;
}