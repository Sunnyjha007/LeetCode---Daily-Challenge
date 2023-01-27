class Solution {
private:
bool isConcat(string word,unordered_set<string>& st,unordered_map<string,bool>& mp){
    int n = word.size();
    if(mp.count(word))return mp[word];
    for(int i=1;i<n;i++){
        string prefix = word.substr(i);
        if(st.count(word.substr(0,i))&&(st.count(prefix)||isConcat(prefix,st,mp)))return mp[word] = true;
    }
    return mp[word] = false;
}
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if(words.size()==0)return {};
        unordered_set<string> st;
        unordered_map<string,bool> mp;
        vector<string> ans;
        for(auto word:words)st.insert(word);
        for(auto word:words){
            if(isConcat(word,st,mp))ans.push_back(word);
        }
        return ans;
    }
};
