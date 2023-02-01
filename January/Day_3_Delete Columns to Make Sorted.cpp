class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt=0;
        int n = strs.size();
        int m = strs[0].size();
        for(int j=0;j<m;j++){
                for(int i=0;i<n-1;i++){
                    if(strs[i][j]>strs[i+1][j]){
                        cnt++;
                        break;
                    }
            }
        }
        return cnt;
        
    }

};
