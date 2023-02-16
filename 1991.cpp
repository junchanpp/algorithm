#include <iostream>
#include <vector>

using namespace std;

typedef struct Tree
{
    string node;
    string leftNode;
    string rightNode;
} Tree;

vector<Tree> v;

void preorder(string s);
void inorder(string s);
void postorder(string s);

// TEST CASE 1
// 7
// A B C
// B D .
// C E F
// E . .
// F . G
// D . .
// G . .
// ----------------------------------
// EXPECTED 1
// ABDCEFG
// DBAECFG
// DBEGFCA
int main()
{
    int n;
    scanf("%d", &n);

    vector<Tree>::iterator iter;
    for (int i = 0; i < n; i++)
    {
        Tree temp;
        cin >> temp.node >> temp.leftNode >> temp.rightNode;
        v.push_back(temp);
    }
    preorder("A");
    cout << endl;
    inorder("A");
    cout << endl;
    postorder("A");
    cout << endl;
}

void preorder(string s)
{
    if (s.compare(".") == 0)
    {
        return;
    }
    cout << s;

    for (Tree tree : v)
    {
        if (s.compare(tree.node) == 0)
        {
            preorder(tree.leftNode);
            preorder(tree.rightNode);
            return;
        }
    }

    return;
}

void inorder(string s)
{

    if (s.compare(".") == 0)
    {
        return;
    }

    for (Tree tree : v)
    {
        if (s.compare(tree.node) == 0)
        {
            inorder(tree.leftNode);
            cout << s;
            inorder(tree.rightNode);
            return;
        }
    }

    return;
}

void postorder(string s)
{
    if (s.compare(".") == 0)
    {
        return;
    }

    for (Tree tree : v)
    {
        if (s.compare(tree.node) == 0)
        {
            postorder(tree.leftNode);
            postorder(tree.rightNode);
            cout << s;
            return;
        }
    }

    return;
}