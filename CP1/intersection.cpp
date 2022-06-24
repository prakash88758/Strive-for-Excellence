#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1, v2, v3;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v1.push_back(ele);
    }

    for (int i = 0; i < m; i++)
    {
        int ele;
        cin >> ele;
        v2.push_back(ele);
    }

    map<int, int> m1;
    for (int i = 0; i < n; i++)
    {
        if (m1.find(v1[i]) != m1.end())
        {
            m1[v1[i]] = m1[v1[i]] + 1;
        }
        else
        {
            m1[v1[i]] = 1;
        }
    }

    // for (auto value : m1)
    // {
    //     cout << value.first << " " << value.second << "\n";
    // }

    for (int i = 0; i < m; i++)
    {
        // int key = v2[i];
        if (m1.find(v2[i]) != m1.end())
            v3.push_back(v2[i]);
    }

    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
}