//merge sort
class Solution {
private:
void merge(vector<int>& nums,int si,int mid,int ei){
    int n1 = mid - si + 1;
    int n2 = ei - mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)left[i] = nums[si + i];
    for(int i=0;i<n2;i++)right[i] = nums[mid+i+1];
    int i=0,j=0,k = si;
    while(i<n1&&j<n2){
        if(left[i]<=right[j]){
            nums[k++] = left[i++];
        }else{
            nums[k++] = right[j++];
        }
    }
    while(i<n1){
        nums[k++] = left[i++];
    }
    while(j<n2){
        nums[k++] = right[j++];
    }
}
void mergeSort(vector<int>& nums,int si,int ei){
    if(si>=ei)return;
    int mid = si + (ei-si)/2;
    mergeSort(nums,si,mid);
    mergeSort(nums,mid+1,ei);
    merge(nums,si,mid,ei);
}
public:
    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums;
        int si = 0,ei = nums.size()-1;
        mergeSort(nums,si,ei);
        return nums;
    }
};



// quick sort
class Solution {
public:
   int part(vector<int>& arr,int start,int last)
 {
     int i=start+1,j=last,temp;
       int pi = arr[start];
     
     while(i<=j){
              if(arr[i]<=pi)i++;
              if(arr[j]>pi)j--;
              if(i<=j)swap(arr[i],arr[j]);
      }
       swap(arr[start],arr[j]);
       return j;
}
    void solve(vector<int>& nums,int si,int ei){
        if(si>=ei)return;
        int pi = part(nums,si,ei);
        solve(nums,si,pi-1);
        solve(nums,pi+1,ei);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums;
        solve(nums,0,n-1);
        return nums;
    }
};
