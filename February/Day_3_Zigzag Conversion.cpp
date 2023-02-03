class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size(),i=0;
        vector<string> st(numRows);
        while(i<n){
            for(int j=0;j<numRows&&i<n;j++){
                st[j].push_back(s[i++]);
            }
            for(int j=numRows-2;j>0&&i<n;j--){
                st[j].push_back(s[i++]);
            }
        }
        s.clear();
        for(int i=0;i<st.size();i++)s+=st[i];
        return s;
    }
};
