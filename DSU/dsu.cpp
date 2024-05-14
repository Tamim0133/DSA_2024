#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int rankt[1000];

int find_root(int i)
{
    if (parent[i] == i)
    {
        return i;
    }
    int root = find_root(parent[i]);
    parent[i] = root;
    return root;
}

int find(int i, int j)
{
    int ri = find_root(i);
    int rj = find_root(j);
    if (ri == rj)
    {
        return 1;
    }
    return 0;
}

void union_set(int i, int j)
{
    int ri = find_root(i);
    int rj = find_root(j);
    if (ri == rj)
    {
        return;
    }
    if (rankt[ri] < rankt[rj])
    {
        parent[ri] = rj;
    }
    else
    {
        parent[rj] = ri;
        if (rankt[ri] == rankt[rj])
        {
            rankt[ri]++;
        }
    }
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        parent[i] = i;
        rankt[i] = 0;
    }
    union_set(2, 3);
    union_set(4, 3);
    union_set(1, 4);
    union_set(6, 8);
    cout << find(1, 3) << endl;
    cout << find(2, 4) << endl;
    cout << find(6, 3) << endl;
    return 0;
}
