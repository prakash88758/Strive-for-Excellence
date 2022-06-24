#include <bits/stdc++.h>

using namespace std;

// string ltrim(const string &);
// string rtrim(const string &);
// vector<string> split(const string &);

/*
 * Complete the 'connectedCell' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */
bool safe(int i, int j, int r, int c, vector<vector<bool>> &visit, vector<vector<int>> matrix, int count)
{
    if(i >= 0 and j >= 0 and i < r and j < c and visit[i][j] == false and matrix[i][j] != 0)
        return true;
    if(i >= 0 and j >= 0 and i < r and j < c and visit[i][j] == true and matrix[i][j] != 0)
        { count--; return true; }
    return false;
}

bool dfs(int i, int j, int r, int c, vector<vector<bool>> &visit, vector<vector<int>> matrix, int count)
{
    count++;
    visit[i][j] = true;
    
    // Right
    if(safe(i, j+1, r, c, visit, matrix))
        if(dfs(i, j+1, r, c, visit, matrix, count))
            return true;
            
     // Left
    if(safe(i, j-1, r, c, visit, matrix))
        if(dfs(i, j-1, r, c, visit, matrix, count))
            return true;
            
     // Up
    if(safe(i-1, j, r, c, visit, matrix))
        if(dfs(i-1, j, r, c, visit, matrix, count))
            return true;
            
     // Down
    if(safe(i+1, j, r, c, visit, matrix))
        if(dfs(i+1, j, r, c, visit, matrix, count))
            return true;
            
    // visit[i][j] = false;
    return true;
}

int connectedCell(vector<vector<int>> matrix) {
    
    int r = matrix.size();
    int c = matrix[0].size();
    int max = INT_MIN;
    
    vector<vector<bool>> visit(r, vector<bool> (c, false));
    
    for(int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) 
            if (matrix[i][j] == 1 && visit[i][j] == false) {
                int count = 0;
                if(dfs(i, j, r, c, visit,  matrix, count))
                    if(count > max)
                    max = count;
            }
    return max;
}

int main(){
    // Solution obj;
    vector<vector<int>>matrix = {{0,1,1},{1,1,0},{0,0,1}};
    // string word = "SEE";
    int e = connectedCell(matrix);
    if(e == true)
        cout << "EXIST";
    else
        cout << "Doesnt EXIST";
    return 0;
}

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string n_temp;
//     getline(cin, n_temp);

//     int n = stoi(ltrim(rtrim(n_temp)));

//     string m_temp;
//     getline(cin, m_temp);

//     int m = stoi(ltrim(rtrim(m_temp)));

//     vector<vector<int>> matrix(n);

//     for (int i = 0; i < n; i++) {
//         matrix[i].resize(m);

//         string matrix_row_temp_temp;
//         getline(cin, matrix_row_temp_temp);

//         vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

//         for (int j = 0; j < m; j++) {
//             int matrix_row_item = stoi(matrix_row_temp[j]);

//             matrix[i][j] = matrix_row_item;
//         }
//     }

//     int result = connectedCell(matrix);

//     fout << result << "\n";

//     fout.close();

//     return 0;
// }

// // string ltrim(const string &str) {
// //     string s(str);

// //     s.erase(
// //         s.begin(),
// //         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
// //     );

// //     return s;
// // }

// // string rtrim(const string &str) {
// //     string s(str);

// //     s.erase(
// //         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
// //         s.end()
// //     );

// //     return s;
// // }

// // vector<string> split(const string &str) {
// //     vector<string> tokens;

// //     string::size_type start = 0;
// //     string::size_type end = 0;

// //     while ((end = str.find(" ", start)) != string::npos) {
// //         tokens.push_back(str.substr(start, end - start));

// //         start = end + 1;
// //     }

// //     tokens.push_back(str.substr(start));

// //     return tokens;
// // }
