/*
Well, unfortunately things didn't go so well for Alex's campers,
 and now there are N campers wandering around the city aimlessly.
 You have to handle Q queries; which consist of two groups finding each other and
 becoming one larger group. After each query, output the difference between the group
 of largest size and group of smallest size. If there is only one group, output 0.
 At first, everyone is in their own group.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int parent[N];
int Size[N];

multiset<int> sizes;

void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
    sizes.insert(1);
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
void merge(int a, int b) // b ke a er tree te merge korbo
{
    sizes.erase(sizes.find(Size[a]));
    sizes.erase(sizes.find(Size[b]));
    sizes.insert(Size[a] + Size[b]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        merge(a, b);
        Size[a] += Size[b];
    }
}

int main()
{
    // Given n nodes , and m edges find connected components
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        make(i);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);

        if (sizes.size() == 1)
            cout << 0 << endl;
        else
        {
            int mn = *(sizes.begin());
            int mx = *(--sizes.end());

            cout << mx - mn << endl;
        }
    }

    return 0;
}