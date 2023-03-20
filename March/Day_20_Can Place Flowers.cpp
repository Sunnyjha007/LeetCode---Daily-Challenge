class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int m = fb.size();
        int count=0;
        for(int i=0;i<m;i++){
            if(fb[i]==0){
                int prev = (i==0||fb[i-1]==0)?0:1;
                int next = (i==m-1||fb[i+1]==0)?0:1;
                if(prev==0&&next==0){
                    fb[i] = 1;
                    count++;
                }
            }
        }
        return count>=n;
    }
};
