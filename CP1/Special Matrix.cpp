// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    int count = 0;

    bool isSafe(int i, int j, int m, int n, vector<vector<bool>>&visited){
        if(i >= 0 and j >= 0 and i < m and j < n and visited[i][j] == false)
            return true;
        return false;
    }

    int countPath(int i, int j, int m, int n, vector<vector<bool>>&visited){
        
        if( i == n-1 and j == n-1)
            return count++;

        visited[i][j] = true;
        
        if(isSafe(i, j+1, m, n, visited))         //RIGHT          
            countPath(i, j+1, m, n, visited);
                

        if(isSafe(i+1, j, m, n, visited))          //DOWN
            countPath(i+1, j, m, n, visited);
                

        visited[i][j] = false;
        return 0;
    }
    
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    // Code here
	    vector<vector<bool>> visited(n, vector<bool> (m, false));
        for( auto x : blocked_cells)
            visited[x[0]][x[1]] = true;

        if(visited[0][0] == true || visited[m-1][n-1] == true)
            return 0;
            
        return (countPath(0, 0, m, n, visited));
            // return count;

        //  return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc = 1;
	// cin >> tc;
	while(tc--){
		int n=3, m=3, k=2;
		// cin >> n >> m >> k;
		vector<vector<int>>blocked_cells = {{1,2},{3,2}};
		// for(int i = 0; i < k; i++){
		// 	int x, y;
		// 	cin >> x >> y;
		// 	blocked_cells.push_back({x, y});
		// }
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends