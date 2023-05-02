class Solution {
private:
int signFunction(int x){
    if(x<0)return -1;
    if(x==0)return 0;
    return 1;
}
public:
    int arraySign(vector<int>& nums) {
        int sign = 1,n = nums.size();
        for(int i=0;i<n;i++){
            if(signFunction(nums[i])==0)return 0;
            else if(signFunction(nums[i])<0)sign*=-1;
        }
        return sign;
    }
};
