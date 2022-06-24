#include<bits/stdc++.h>

using namespace std;

int binarysearch(vector<int> ranked, int key)
{
    int lb = 0;
    int ub = ranked.size() - 1;
   
    
    while (lb <= ub) {
         int mid = (lb+ub)/2;
        if(ranked[mid] == key)
         return mid;
        else if(ranked[mid] < key && ranked[mid-1] >= key)
         return mid-1;
        else if(ranked[mid] > key && ranked[mid+1] <= key)
         return mid+1;
        else if(ranked[mid] < key)
         ub = mid -1;
        else
         lb = mid + 1;
    }
    return -1;
}

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    
    // sort(ranked.rbegin(), ranked.rend());
    
    vector<int> res;
    vector<int> rank;
    
    rank.push_back(1);
    int n = ranked.size();
    
    for (int i = 1; i < n; i++) {
        if (ranked[i] == ranked[i-1]) 
         rank[i] = rank[i-1];
        else 
         rank[i] = rank[i-1] + 1;
    }
    
    for (int i = 0; i < player.size(); i++) {
        if(player[i] > ranked[0])
         res[i] = 1;
        else if(player[i] < ranked[n-1])
         res.push_back(rank[n-1] + 1);
        else
        {
            int idx = binarysearch(ranked, player[i]);
            res[i] = rank[idx];
        }
    }
    return res;
}

int main()
{
    vector<int> ranked = {100, 100, 50, 40, 40, 20, 10};
    vector<int> player = {5, 25, 50, 120};

    vector<int> result;

    result = climbingLeaderboard(ranked, player);

    for (int  i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    
}