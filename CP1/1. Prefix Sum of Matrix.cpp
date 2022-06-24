#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    // cin >> row >> col;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    row = matrix.size();
    col = matrix[0].size();

    cout << row << "\n";
    cout << col << "\n";

    // for (int i = 0; i < row; i++)
    // {
    //     vector<int> vec;
    //     for (int j = 0; j < col; j++)
    //     {
    //         vector<int> vec;
    //         int ele;
    //         cin >> ele;
    //         vec.push_back(ele);
    //     }
    //     matrix.push_back(vec);
    // }

    for( int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j];
        }
        cout << "\n";
        
    }
    
}