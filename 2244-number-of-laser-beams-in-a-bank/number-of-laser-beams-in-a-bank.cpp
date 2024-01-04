class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prevCount = 0;
        for(int i=0; i<bank.size(); i++){
            int currCount = 0;
            for(char j:bank[i]){
                if(j == '1'){
                    currCount += 1;
                }
            }
            if(currCount){
                ans += prevCount * currCount;
                prevCount = currCount;
            }
        }
        return ans;
    }
};