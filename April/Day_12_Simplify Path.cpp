class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int n = path.length();
        for(int i=0;i<n;i++){
            if(path[i]=='/')continue;
            string curr="";
        while(i<n&&path[i]!='/'){
            curr+=path[i];
            i++;
          }
            i--;
            if(curr==".")continue;
            if(curr==".."){
                if(!s.empty())s.pop();
                continue;
            }
            s.push(curr);
        }
        if(s.empty())return "/";
        string ans="";
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }
        return ans;
    }
};
