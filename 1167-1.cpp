#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct Edge
{
    int nextNode;
    int cost;
} Edge;

Edge makeEdge(int nextNode, int cost)
{
    Edge edge = {nextNode, cost};
    return edge;
}

int n;
int longestCost = 0;
int longestNode = 0;
vector<Edge> edge[100100];
bool visited[100100] = {
    false,
};
void dfs(int node, int cost);

int main()
{
    scanf("%d", &n);

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
            edge[startNum].push_back(makeEdge(tempNode, tempDistance));
        }
    }

    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(longestNode, 0);
    cout << longestCost;
}

void dfs(int node, int cost)
{
    if (visited[node])
    {
        return;
    }
    if (longestCost < cost)
    {
        longestCost = cost;
        longestNode = node;
    }

    visited[node] = true;
    vector<Edge>::iterator iter;
    for (iter = edge[node].begin(); iter != edge[node].end(); iter++)
    {
        Edge ed = *iter;
        dfs(ed.nextNode, ed.cost + cost);
    }
}