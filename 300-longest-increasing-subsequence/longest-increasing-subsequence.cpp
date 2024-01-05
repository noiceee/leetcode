// class Solution {
// public:
//     int LIS(int i, vector<int>& nums){
//         if (nums[i+1] > nums[i]) {

//         } 
//         return (1 + LIS(i + 1));
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         // int i=0;
//         // int ans = 1;
//         // int count = 1;
//         // while(i<nums.size() - 1){
//         //     if(nums[i+1] > nums[i]){
//         //         count++;
//         //     } else {
//         //         if (count > ans){
//         //             ans = count;
//         //         }
//         //         count = 1;
//         //     }
//         //     i++;
//         // }
//         // return ans;
//         // int minNumber = INT_MAX;
//         // int ans = 1;
//         // for(int i=0; i<nums.size()-1; i++){
//         //     if(nums[i]>minNumber){
//         //         continue;
//         //     }
//         //     int count = 1;
//         //     int temp = i;
//         //     for(int j=i+1; j<nums.size(); j++){
//         //         if(nums[j]>nums[temp]){
//         //             count++;
//         //             temp = j;
//         //         }
//         //     }
//         //     if(count > ans){
//         //         ans = count;
//         //     }
//         //     minNumber = nums[i];
//         // }
//         // return ans;

//     }
// };

class Solution {
public:

    int f(int index, int prev_ind, vector<int>&nums, int n,vector<vector<int>>&dp ){
        if(index==n)return 0;
        if(dp[index][prev_ind+1] != -1)return dp[index][prev_ind+1];    
        int len = 0 + f(index+1, prev_ind, nums, n,dp);

        if(prev_ind == -1 || nums[index] > nums[prev_ind]){
            len = max(len, 1 + f(index+1, index, nums, n,dp));
        } 
        return dp[index][prev_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }
};

