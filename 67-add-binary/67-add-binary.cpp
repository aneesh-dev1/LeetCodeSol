class Solution {

public:
    string addBinary(string a, string b) {
        string ans="";
        int carry=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;
        int sum;
        while(i<a.size() || i<b.size()){
            sum=carry;
            if(i<a.size()) sum+=a[i]-'0';
            if(i<b.size()) sum+=b[i]-'0';
            
            if(sum==0){
                carry=0;
                ans+='0';
            }
            else if(sum==1){
                carry=0;
                ans+='1';
            }
            else if(sum==2){
                carry=1;
                ans+='0';
            }
            else{
                carry=1;
                ans+='1';
            }
            i++;
        }
        if(carry==1){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};