class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int cnt=0,n = people.size(),sum=0;
        int si=0,ei=n-1;
        while(si<=ei){
             sum =  people[si] + people[ei];
             if(sum<=limit){
                 cnt++;si++;ei--;
             }else{
                 cnt++;ei--;
             }
        }
        return cnt;
    }
};
