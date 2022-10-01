class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        unordered_set<char> setter;
        while(j<s.size()){
            while(setter.find(s[j]) !=setter.end()){
                setter.erase(s[i]);
                i++;
            }
            setter.insert(s[j]);
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};