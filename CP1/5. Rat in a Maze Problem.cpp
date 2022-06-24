//Rat in a Maze Problem
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(int i, int j, int n, vector<vector<bool>>&visited, vector<vector<int>> &m){
        if(i >= 0 and j >= 0 and i < n and j < n and visited[i][j] == false and m[i][j] != 0)
            return true;
        return false;
    }
    
    void Path(int i, int j, int n, vector<vector<bool>>&visited, vector<vector<int>> &m, vector<string>&result, string osf){
        if( i == n-1 and j == n-1){
            result.push_back(osf);
            return;
        }
        visited[i][j] = true;
        
        if(isSafe(i, j+1, n, visited, m)){          //RIGHT
            osf.append("R");          
            Path(i, j+1, n, visited, m, result, osf);
            osf.pop_back();
        }

        if(isSafe(i, j-1, n, visited, m)){           //LEFT
            osf.append("L");
            Path(i, j-1, n, visited, m, result, osf);
            osf.pop_back();
        }

        if(isSafe(i+1, j, n, visited, m)){          //DOWN
            osf.append("D");
            Path(i+1, j, n, visited, m, result, osf);
            osf.pop_back();
        }

        if(isSafe(i-1, j, n, visited, m)){          //UP
            osf.append("U");
            Path(i-1, j, n, visited, m, result, osf);
            osf.pop_back();
        }

        visited[i][j] = false;
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>result;
        if(m[0][0] == 0)
            return result;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        string osf = "";
        Path(0,0,n,visited,m,result,osf);
        sort(result.begin(),result.end());
        return result;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
