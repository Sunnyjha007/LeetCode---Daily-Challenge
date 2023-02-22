class Solution {
private:
bool solve(int mid,vector<int>& weights,int n,int days){
    int sum=0,d=1;
    for(int i=0;i<n;i++){
        if(sum+weights[i]<=mid)sum+=weights[i];
        else{
            sum = weights[i];
            d++;
        }
    }
    if(d<=days)return true;
    return false;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            if(solve(mid,weights,n,days)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
