class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        int j=0;
        for(int i=0;i<size;i++){
            if(s[i] == ' '){
                reverse(s.begin()+j,s.begin()+i);
                j = i+1;
            }
            
        }
        reverse(s.begin()+j,s.end());
        return s;
    }
};