#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    // vector<vector<bool>> visited( 6, vector<bool> (6, false));
public:
    // bool visited[6][6];
    
    
    bool isSafe(int i, int j, int row, int col, vector<vector<char>>& board, vector<vector<bool>> &visited, string word, int index)
    {
        if(i >= 0 && j >= 0 && i < row && j < col && visited[i][j] == false && board[i][j] == word[index+1])
            return true;
        return false;
    }
   // a0aaaabcd
    
   bool dfs(int i, int j, int row, int col, vector<vector<char>>& board, vector<vector<bool>> &visited, string word, int index)
    {
        // if (i > row-1 || i < 0 || j > col-1 || j < 0 || index == word.length() || vs[i][j] == true) 
        //     return false;    
	// if (board[i][j] != word[index]) return false;        
	if (index == word.length()-1) 
        return true;
	visited[i][j] = true;
        
       // right
       if(isSafe(i, j+1, row, col, board, visited, word, index))
           if(dfs(i, j+1, row, col, board, visited, word, index+1))
               return true;
       
       // left
       if(isSafe(i, j-1, row, col, board, visited, word, index))
           if(dfs(i, j-1, row, col, board, visited, word, index+1))
               return true;
       
       // up
       if(isSafe(i-1, j, row, col, board, visited, word, index))
           if(dfs(i-1, j, row, col, board, visited, word, index+1))
               return true;
       
       // down
       if(isSafe(i+1, j, row, col, board, visited, word, index))
           if(dfs(i+1, j, row, col, board, visited, word, index+1))
               return true;
           
       visited[i][j] = false;
       return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool> (col, false));

        bool exists;
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(word[0] == board[i][j])
                    exists = dfs(i, j, row, col, board, visited, word, 0);
                if(exists == true)
                    return exists;
            }
            // if(exists == true)
            //   return exists;
        }
            
        return exists;
    }
};

int main(){
    Solution obj;
    vector<vector<char>>b = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "SEE";
    bool e = obj.exist(b,word);
    if(e == true)
        cout << "EXIST";
    else
        cout << "Doesnt EXIST";
    return 0;
}