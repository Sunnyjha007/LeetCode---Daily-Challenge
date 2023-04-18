class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(),n = word2.size(),i=0,j=0,k=0;
        string ans;
        while(i<m&&j<n){
            if(k%2==0)ans.push_back(word1[i++]);
            else ans.push_back(word2[j++]);
            k++;
        }
        while(i<m){
            ans.push_back(word1[i++]);
        }
        while(j<n){
            ans.push_back(word2[j++]);
        }
        return ans;
    }
};
