class Solution {
private:
bool banana(vector<int>& piles,int val,int h){
    int cnt = 0;
    for(int i=0;i<piles.size();i++){
        cnt+= piles[i]/val;
        if(piles[i]%val)cnt++;
    }
    return cnt>h;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        while(low<high){
            int mid = low + (high - low)/2;
            if(banana(piles,mid,h)){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};
