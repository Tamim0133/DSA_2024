// https://www.youtube.com/watch?v=LeMfdGyN-F0
//  Watch last 1 min of the video
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");
    for (int i = 1; i <= n; i++)
    {
        cout << "Binary representation of " << i << ": " << q.front() << "\n";
        string tmp = q.front();
        cout << "TEmp : " << tmp << endl;
        q.pop();
        q.push(tmp + "0");
        q.push(tmp + "1");
    }
    return 0;
}