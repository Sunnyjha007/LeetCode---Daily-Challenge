class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), cnt=0,x=0;
        vector<int> v(arr[n-1]+k,0);
        for(int i=0;i<n;i++){
            v[arr[i]-1] = 1;
        }
        int i;
        for( i=0;i<arr[n-1]+k;i++){
            if(!v[i])x++;
            if(k==x)return i+1;
        }
        return -1;
    }
};
