class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bytes_rem = 0;
        for(auto x:data){
            string s = "";
            for(int i=0;i<8;i++){
                s += (x%2==0 ? "0" : "1");
                x = x/2;
            }
            reverse(s.begin(),s.end());
            if(bytes_rem == 0){
                if(s[0] == '0')
                    continue;
                int i=0;
                for(i=0;i<8;i++){
                    if(s[i] == '0'){
                        if(i == 1) return false;
                        bytes_rem = i-1;
                        break;
                    }
                }
                if(i==8 || bytes_rem>=4){
                    return false;
                }
            }
                else if(bytes_rem > 0){
                    if(s[0] != '1' || s[1] != '0')
                        return false;
                    bytes_rem--;
                }
        }
        return (bytes_rem == 0);
    }
};