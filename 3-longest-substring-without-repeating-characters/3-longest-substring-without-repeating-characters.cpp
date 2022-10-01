class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        unordered_set<char> us;
        while(j<s.size()){
            char c = s[j];
            while(us.find(c) != us.end()){
                us.erase(s[i]);
                ++i;
            }
            us.insert(c);
            ans = max(ans,j-i+1);
            ++j;
        }
        return ans;
    }
};