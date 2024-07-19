#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Edge
{
    int parentNode;
    int childNode;
    int distance;
} Edge;

bool visited[100100] = {
    false,
};
Edge edge[100100];

int n;
int i;

int maxNum = 0;

int calculateDiameter(int node, int startIndex, int distance);

bool cmp(const Edge &e1, const Edge &e2)
{
    if (e1.parentNode < e2.parentNode)
    {
        return true;
    }
    else if (e1.parentNode == e2.parentNode)
    {
        return e1.childNode < e2.childNode;
    }
    else
    {
        return false;
    }
}

int main()
{
    scanf("%d", &n);

    i = 0;
    for (int j = 0; j < n; j++)
    {
        int startNum;
        scanf("%d", &startNum);
        while (1)
        {
            int tempNode;
            int tempDistance;
            scanf("%d", &tempNode);
            if (tempNode == -1)
                break;
            scanf("%d", &tempDistance);
            edge[i].parentNode = startNum;
            edge[i].childNode = tempNode;
            edge[i].distance = tempDistance;
            i++;
        }
    }

    sort(edge, edge + i, cmp);

    calculateDiameter(1, 0, 0);

    printf("%d", maxNum);
}

int calculateDiameter(int node, int startIndex, int distance)
{
    int nextStartIndex;
    vector<int> distanceList;
    visited[node] = true;

    vector<int> indexList;

    for (nextStartIndex = startIndex; nextStartIndex < i && (node >= edge[nextStartIndex].parentNode); nextStartIndex++)
    {
        if (node == edge[nextStartIndex].parentNode && visited[edge[nextStartIndex].childNode] != true)
        {
            indexList.push_back(nextStartIndex);
        }
    }

    vector<int>::iterator iter;
    for (iter = indexList.begin(); iter != indexList.end(); iter++)
    {
        int index = *iter;
        int dis = calculateDiameter(edge[index].childNode, nextStartIndex, edge[index].distance);
        distanceList.push_back(dis);
    }

    if (distanceList.empty())
    {
        return distance;
    }
    int maxDis = 0, max2Dis = 0;
    for (int j = 0; j < distanceList.size(); j++)
    {
        if (maxDis < distanceList[j])
        {
            max2Dis = maxDis;
            maxDis = distanceList[j];
        }
        else if (max2Dis < distanceList[j])
        {
            max2Dis = distanceList[j];
        }
    }
    if (maxNum < maxDis + max2Dis)
    {
        maxNum = maxDis + max2Dis;
    }
    return maxDis + distance;
}