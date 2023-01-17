class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flip=0,one=0,n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one++;
            }else{
                if(one==0)continue;
                else flip++;
            }
            if(one<flip)flip = one;
        }
        return flip;
    }
};
/*
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(),ans = INT_MAX;
        vector<int> onecount(n,0),zerocount(n,0);
        onecount[0] = 0,zerocount[n-1]=0;
        for(int i=1;i<n;i++){
            if(s[i-1]=='1')onecount[i] = onecount[i-1]+1;
            else onecount[i] = onecount[i-1];
            if(s[n-i]=='0')zerocount[n-i-1] = zerocount[n-i]+1;
            else zerocount[n-i-1] = zerocount[n-i];
        }
        for(int i=0;i<n;i++){
            ans = min(ans,zerocount[i]+onecount[i]);
        }
        return ans;
    }
};
*/
/*
class Solution {
private:
int onecount(string s){
    int n = s.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')cnt++;
    }
    return cnt;
}
int zerocount(string s){
    int n = s.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0')cnt++;
    }
    return cnt;
}
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int mini = INT_MAX;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]+= onecount(s.substr(0,i));
            ans[i]+= zerocount(s.substr(i+1));
            mini = min(mini,ans[i]);
        }
        return mini;
    }
};
*/
