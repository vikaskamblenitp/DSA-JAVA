#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<bool> >&dp,vector<int>&arr,int n,int sum){
	if(sum == 0) return true;
	else if(n==0) return false;

	if(arr[n-1] <= sum){
		return dp[n][sum] = solve(dp,arr,n-1,sum-arr[n-1]) or solve(dp,arr,n-1,sum);
	}
	else return dp[n][sum] = solve(dp,arr,n-1,sum); 
}

int main(){
	int n,sum=0;
	cin>>n;
	vector<int> arr(n);
	vector<bool> v(n);
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		sum+=arr[i];
	}

	cout<<sum<<endl;
	if(sum%2== 0){
		sum /=2;
		vector<vector<bool> > dp(n+1, vector<bool>(sum+1,false));
		
		for(int i=0;i<=n;i++){
			for(int j=0;j<=sum;j++){
				if(j==0) dp[i][j]= true;
				else if(i == 0) dp[i][j] = false;
				else if(arr[i-1] <= j){
					dp[i][j]  = dp[i-1][j-arr[i-1]] or dp[i-1][j];
				}
				else dp[i][j] = dp[i-1][j];
			}
		}

		cout<<dp[n][sum]<<" "<<sum<<endl;
	}
	else cout<<0<<endl;
		
return 0;
}