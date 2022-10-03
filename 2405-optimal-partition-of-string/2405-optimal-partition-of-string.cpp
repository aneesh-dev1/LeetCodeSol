class Solution {
public:
    int partitionString(string s) {
        int i=0,j=0,ans=1;
        unordered_set<char> set;
        while(j<s.size()){
            if(set.find(s[j]) !=set.end()){
                ans++;
                set.clear();
            }
            set.insert(s[j]);
            j++;
        }
        return ans;
    }
};