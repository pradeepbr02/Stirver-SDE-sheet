class Solution {
public:
    bool subsetSum(vector<int>&nums , int sum){
        int n=nums.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<sum+1;j++){
                    if(nums[i-1] <=j){
                        dp[i][j]=dp[i-1][j-nums[i-1]] or dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        
        return dp[n][sum];
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        if(sum%2!=0){
            return false;
        }
        return subsetSum(nums , sum/2);
    }
};