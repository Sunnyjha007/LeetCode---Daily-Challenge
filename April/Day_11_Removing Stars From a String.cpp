class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]!='*')st.push(s[i]);
            else {
                if(st.empty())continue;
                else st.pop();
            }
        }
        s.clear();
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
