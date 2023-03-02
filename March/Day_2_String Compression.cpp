class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string ans = "";
        int c=1;
        for(int i=0;i<n;i++){
            if(i<n-1&&chars[i]==chars[i+1]){
                c++;
                //i++;
            }else{
            ans+=chars[i];
            if(c==1)continue;
            ans+= to_string(c);
            c=1;
            }
        }
        chars.clear();
        for(int i=0;i<ans.size();i++)chars.push_back(ans[i]);
        return ans.size();
    }
};
