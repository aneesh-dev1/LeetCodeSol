class Solution {
public:
    bool isPalindrome(int x) {
       long long rev = 0;
      if(x<0)
          return false;
        long long int temp = x;
        while(temp!=0){
            int temp1 = temp % 10;
            rev = rev *10 + temp1;
            temp/=10;
        }
        return (rev == x)?true:false;
    }
};