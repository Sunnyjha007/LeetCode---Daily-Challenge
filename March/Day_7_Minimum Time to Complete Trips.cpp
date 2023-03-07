class Solution {
private:
long long totalTripInGivenTime(vector<int>& time,long long val){
    long long count = 0l;
    for(auto it:time){
        count+= ((long long)val)/it;
    }
    return count;
}
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long mini = (*min_element(time.begin(),time.end()));
        long long high = totalTrips*mini;
        //cout<<high<<" ";
        while(low<high){
            long long mid = low + (high - low)/2;
            long long count = totalTripInGivenTime(time,mid);
            // cout<<count<<endl;
            if(count<totalTrips)low = mid + 1;
            else high = mid;
        } 
        return low;
    }
};
