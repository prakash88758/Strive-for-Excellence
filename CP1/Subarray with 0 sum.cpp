// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        
        vector <int> prefixSum(n,0);
        // vector <int> elements[n];
        
        prefixSum[0] = arr [0];
        
        for( int i=1; i<n; i++)
        {
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
        
        set<int> seen;
        for( int i=0; i<n; i++)
        {
            if( seen.find(prefixSum[i]) != seen.end() || prefixSum[i] == 0)
            return true;
            seen.insert(prefixSum[i]);
        }
        return false;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends