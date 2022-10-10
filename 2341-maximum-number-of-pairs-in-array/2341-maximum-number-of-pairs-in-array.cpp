class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int pairs = 0;
        int odd = 0;
        for(auto it:mp){
            if(it.second % 2 == 0)
                pairs+=it.second/2;
            else{
                pairs+=it.second/2;
                odd++;
            }
        }
        return {pairs,odd};
    }
};