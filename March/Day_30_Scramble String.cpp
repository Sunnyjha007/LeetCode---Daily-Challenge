class Solution {
public:
    unordered_map<string,int> map;
    bool solve(string s1,string s2){
        int n = s1.size();
        if(s1.compare(s2)==0)return true;
        string key = s1 + " " + s2;
        if(map.find(key)!=map.end())return map[key];
        bool flag = false;
        for(int i=1;i<=n-1;i++){
            bool ans1 = solve(s1.substr(0,i),s2.substr(0,i))&&solve(s1.substr(i,n-i),s2.substr(i,n-i));
            bool ans2 = solve(s1.substr(0,i),s2.substr(n-i,i))&&solve(s1.substr(i),s2.substr(0,n-i)); 
            if(ans1||ans2){
                flag = true;
                break;
            }
        }
        return map[key] = flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size())return false;
        return solve(s1,s2);
    }
};
