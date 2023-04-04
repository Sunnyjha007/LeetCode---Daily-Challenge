class Solution {
public:
    int partitionString(string s) {
        int n = s.size(),cnt=0;
        vector<int> v(26,0);
        for(int i=0;i<n;i++){
            if(v[s[i]-'a']!=0){
               for(int j=0;j<26;j++)v[j] = 0;
                cnt++;
                i--;
            }else{
                v[s[i]-'a']++;
            }
        }
        for(int i=0;i<26;i++)if(v[i]){cnt++;break;}
        return cnt;
    }
};
