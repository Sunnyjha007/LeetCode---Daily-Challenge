class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        vector<int> freq(26,0);
        int ans = 0,cnt=0;
        int i=0,j=0;
        while(j<n){
            if(j-i==k){
                cnt= freq[0]+freq[4]+freq[8]+freq[14]+freq[20];
                freq[s[i]-'a']--;
                i++;
                ans = max(ans,cnt);
            }else{
                freq[s[j]-'a']++;
                j++;
            } 
        }
        cnt =  freq[0]+freq[4]+freq[8]+freq[14]+freq[20];
        if((j-i)<=k)ans = max(ans,cnt);
        return ans;
    }
};
