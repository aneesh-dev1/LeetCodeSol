class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            int curr=0;
            if(mp.find(nums[i]-1) == mp.end()){
                while(mp.find(nums[i]++) != mp.end()){
                    curr++;
                    ans = max(ans,curr);
                }
            }
        }
        return ans;
    }
};