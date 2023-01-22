class Solution {
private:
bool isParlindrome(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])return false;
        else {i++;j--;}
    }
    return true;
}
void solve(string s,vector<vector<string>>& ans,vector<string> v){
    if(s.size()==0){
        ans.push_back(v);
        return;
    }
    for(int i=0;i<s.size();i++){
        string curr = s.substr(0,i+1);
        string pending = s.substr(i+1);
        if(isParlindrome(curr)){
            v.push_back(curr);
            solve(pending,ans,v);
            v.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(s,ans,v);
        return ans;
    }
};
