class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int lower=0,upper=0,first=0;
        for(int i=0;i<n;i++){
            if(isupper(word[i])){
                upper++;
                if(i==0)first=1;
            }else{
                lower++;
            }
        }
        if(upper==n||lower==n)return true;
        if(upper==1&&first)return true;
        return false;
    }
};
