class Solution{
    public:

    int countSubset(vecotr<int>&nums , int sum){
        int n = nums.size();
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
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }



    int countSubsetDifference(vector<int>&nums , int diff){
        int sum=0;
        int sumofArray=0;
        for(int i=0;i<nums.size();i++){
            sumofArray+=nums[i];
        }
        sum=(diff + sumofArray)/2;

        return countSubset(nums , sum);
    }
};