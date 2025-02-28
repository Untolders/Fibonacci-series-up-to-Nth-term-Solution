#################################################################  Question  #################################################################################################################################################
You are given an integer n, return the fibonacci series till the nth(0-based indexing) term. Since the terms can become very large return the terms modulo 109+7.

Example 1:

Input:
n = 5
Output:
0 1 1 2 3 5
Explanation:
0 1 1 2 3 5 is the Fibonacci series up to the 5th term.
Example 2:

Input:
n = 10
Output:
0 1 1 2 3 5 8 13 21 34 55
Explanation:
0 1 1 2 3 5 8 13 21 34 55 is the Fibonacci series up to the 10th term.
Your Task:
You don't need to read input or print anything. Your task is to complete the function Series() which takes an Integer n as input and returns a Fibonacci series up to the nth term.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraint:
1 <= n <= 105

 #################################################################################  Solution  #################################################################################################################################

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 long long MOD = 1e9+7;
class Solution {
  public:
  int  solve(int n,vector<int>&dp){
      if(n<=0){
         return 0;
      }
      if(n==1){
          return 1;
      }
      if(dp[n]!=-1){
          return dp[n]%MOD;
      }
      dp[n]=(solve(n-1,dp)+solve(n-2,dp))%MOD;
      return dp[n]%MOD;
  }
    vector<int> Series(int n) {
        // Code here
  
        vector<int>dp(n+1,-1);
        solve(n,dp);
        dp[0]=0;
        dp[1]=1;
        return dp;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
