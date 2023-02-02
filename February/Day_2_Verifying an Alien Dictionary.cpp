class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]] = i+1;
        }
        for(int i=1;i<words.size();i++){
            string a = words[i-1];
            string b = words[i];
            int idx1=0,idx2=0;
            while(a[idx1]==b[idx2]){
                idx1++;idx2++;
            }
            cout<<b[idx2]<<" ";
            cout<<mp[b[idx2]];
            if(mp[a[idx1]]>mp[b[idx2]])return false;
        }
        return true;
    }
};
