//290. Word Pattern

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size();
         vector<string>st;
        string word;
        stringstream iss(s);
        while(iss >> word){
            st.push_back(word);
        }
        if(st.size()!=pattern.size())return false;
        unordered_map<char,string> mp;
        set<string> check;
        for(int i=0;i<st.size();i++){
            if(mp.find(pattern[i])!=mp.end()){
                if(mp[pattern[i]]!=st[i])return false;
            }else{
                if(check.count(st[i]))return false;
                mp[pattern[i]] = st[i];
                check.insert(st[i]);
            }
        }
        return true;
    }
};
