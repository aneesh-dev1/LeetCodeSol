class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int dir = 0;
        int T = 0;
        int D = matrix.size()-1;
        int L=0;
        int R = matrix[0].size()-1;
        int i=0;
        while(T<=D && L<=R){
            if(dir == 0){
                for(i=L;i<=R;i++){
                    ans.push_back(matrix[T][i]);
                }
                T+=1;
            }
            else if(dir == 1){
                for(i = T;i<=D;i++)
                    ans.push_back(matrix[i][R]);
                R-=1;
            }
            else if(dir == 2){
                for(i=R;i>=L;i--)
                    ans.push_back(matrix[D][i]);
                D-=1;
            }
            else if(dir == 3){
                for(i = D;i>=T;i--){
                    ans.push_back(matrix[i][L]);
                }
                L+=1;
            }
            
            dir = (dir+1)%4;
        }
        return ans;
    }
};