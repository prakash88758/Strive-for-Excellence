class Solution {
public:
    
    bool safe(int i, int j, int r, int c, vector<vector<char>> &grid)
{
    if(i >= 0 and j >= 0 and i < r and j < c and grid[i][j] != '0')
    {
        // visit[i][j] = true;
        // grid[i][j] = '0';
        return true;
    }
    
    return false;
}

void dfs(int i, int j, int r, int c, vector<vector<char>> &grid)
{
    
    // visit[i][j] = true;
    grid[i][j] = '0';
    
    // Right
    if(safe(i, j+1, r, c, grid))
        dfs(i, j+1, r, c, grid);
            // return true;
            
     // Left
    if(safe(i, j-1, r, c, grid))
        dfs(i, j-1, r, c, grid);
            // return true;
            
     // Up
    if(safe(i-1, j, r, c, grid))
        (i-1, j, r, c, grid);
            // return true;
            
     // Down
    if(safe(i+1, j, r, c, grid))
        dfs(i+1, j, r, c, grid);
            // return true;
            
    // visit[i][j] = false;
    return ;
}


    int numIslands(vector<vector<char>>& grid) {
    
    int r = grid.size();
    int c = grid[0].size();
    // int max = INT_MIN;
        int count = 0;
    
    // vector<vector<bool>> visit(r, vector<bool> (c, false));
    
    for(int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) 
            if (grid[i][j] == '1' ) {
                count++;
                dfs(i, j, r, c, grid);
                   
            }
    return count;
    }
};

int main(){
    Solution obj;
    vector<vector<char>> g = {{'1','0','1','1','1'},{'1','0','1','0','1'},{'1','1','1','0','1'}};
    // string word = "SEE";
    int e = obj.numIslands(g);
    // if(e == true)
    //     cout << "EXIST";
    // else
    //     cout << "Doesnt EXIST";
    return 0;
}