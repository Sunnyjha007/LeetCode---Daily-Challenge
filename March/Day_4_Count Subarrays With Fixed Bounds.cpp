class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        vector<int> less,more;
        for(int i=0;i<n;i++){
            if(nums[i]==minK)less.push_back(i);
            if(nums[i]==maxK)more.push_back(i);
        }
        for(int i=0;i<n;i++){
            if(nums[i]<minK||nums[i]>maxK)continue;
            int l = i;
            while(i<n&&nums[i]>=minK&&nums[i]<=maxK)i++;
            i--;
            int left = l - 1;
            for(int j=l;j<=i;j++){
                if(nums[j]==minK){
                    int nxt = lower_bound(more.begin(),more.end(),j) - more.begin();
                    long long cnt1 = j - left;
                    if(nxt==more.size())continue;
                    long long cnt2 = i - more[nxt] + 1;
                    if(cnt2>0)ans+= cnt1*cnt2;
                    left = j;
                }else if(nums[j]==maxK){
                    int nxt = lower_bound(less.begin(),less.end(),j) - less.begin();
                    long long cnt1 = j - left;
                    if(nxt==less.size())continue;
                    long long cnt2 = i - less[nxt] + 1;
                    if(cnt2>0)ans+= cnt1*cnt2;
                    left = j;
                }
            }
        }
        return ans;
    }
};
