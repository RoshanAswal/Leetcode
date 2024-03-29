//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int sol(int arr[],int n,int i,int prev,vector<vector<int>> &dp){
	    if(i==n)return 0;
	    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int ans=sol(arr,n,i+1,prev,dp);
        int ans1=0;
        if(prev<0 || arr[i]>arr[prev])
            ans1=sol(arr,n,i+1,i,dp)+arr[i];
        return dp[i][prev+1]=max(ans,ans1);
	}
	int maxSumIS(int arr[], int n)  
	{  
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	    return sol(arr,n,0,-1,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends