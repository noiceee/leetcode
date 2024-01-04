class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(auto i:nums){
            if(umap.find(i) != umap.end()){
                umap[i]++;
            } else {
                umap[i] = 1;
            }
        }
        int ans = 0;
        for(auto ele:umap){
            int i = ele.second;
            if(i == 1){
                return -1;
            }
            if (i%3 == 0){
                ans += i/3;
            } else {
                ans += i/3 + 1;
            }
        }
        return ans;
    }
};