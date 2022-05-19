class Solution {
public:
   int dp[201][201];
	Solution(){
		memset(dp,-1,sizeof(dp)); 
	}
	int dfs(int prev,int i,int j,vector<vector<int>>& matrix,int &r,int &c){
		 if(i>=r or i<0 or j>=c or j<0 or matrix[i][j]<=prev) return 0; 
		 if(dp[i][j]!=-1) return dp[i][j];
		 int left=1,right=1,up=1,down=1;
		 left=dfs(matrix[i][j],i,j-1,matrix,r,c);
		 right=dfs(matrix[i][j],i,j+1,matrix,r,c);
		 up=dfs(matrix[i][j],i-1,j,matrix,r,c);
		 down=dfs(matrix[i][j],i+1,j,matrix,r,c);
		 return dp[i][j]=max({left,right,up,down})+1;
	}
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int ans=1,r=matrix.size(),c=matrix[0].size();
		for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix[i].size();j++){
				 int temp=dfs(-1,i,j,matrix,r,c);
				ans=max(ans,temp);
			}
		}
		return ans;
	}
};