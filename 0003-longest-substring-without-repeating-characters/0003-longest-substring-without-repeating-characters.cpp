class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int i=0,j=0;
        unordered_set<int> s;
        int ans = 0;
        while(j<str.size()){
            if(s.find(str[j]) != s.end()){
                while(s.find(str[j]) != s.end()){
                    s.erase(str[i]);
                    i++;
                }
            }
            s.insert(str[j]);
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};