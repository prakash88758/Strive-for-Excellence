#include <bits/stdc++.h>
 
using namespace std;


 // } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
    {
    //Your code goes here
        
        sort(arr2, arr2+n);
        
        vector<int> res;
        int count = 0;
        
        for(int i = 0; i < m; i++)
        {
            count = upper_bound(arr2, arr2+n, arr1[i]) - arr2;
            res.push_back(count);
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        // int m,n;
        // cin>>m>>n;
        int arr1[] = {4, 8, 7, 5, 1};
        int arr2[] = {4, 48, 2, 0, 1, 1, 5};
        int m = sizeof(arr1)/sizeof(arr1[0]);
        int n = sizeof(arr2)/sizeof(arr2[0]);
        // for(int i=0;i<m;i++)
        // cin>>arr1[i];
        // for(int j=0;j<n;j++)
        // cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends