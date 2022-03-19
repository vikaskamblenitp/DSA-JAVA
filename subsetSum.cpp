#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<bool>> &dp, int n, vector<int>& arr,int sum){
	if(sum == 0) return true;
	else if(n==0) return false;
	if(arr[n-1]<=sum){
		dp[n][sum] = solve(dp,n-1,arr,sum-arr[n-1]) or solve(dp,n-1,arr,sum);
	}
	else dp[n][sum] = solve(dp,n-1,arr,sum);
return dp[n][sum];
}

int main(){
	int n,sum;
	cin>>n>>sum;
	vector<int> arr(n);
	//bool dp[n+1][sum+1];
	vector<vector<bool> > dp(n+1, vector<bool>(sum+1, false));
	//std::vector<<std::vector<bool> > dp(n+1);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<solve(dp,n,arr,sum)<<endl;	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(j==0){
				dp[i][j] = true;
			}
			else if(i==0) dp[i][j] = false;
			else if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}
			else dp[i][j] = true and dp[i-1][j];
		}
	}	
	
	//cout<<"vikas";
	cout<<dp[n][sum]<<endl;
	
	
	return 0;
}