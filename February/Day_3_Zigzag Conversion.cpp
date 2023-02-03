class Solution{
    public:
string convert(string s, int nRows) {
        if(nRows <= 1) return s;
        string result = "";
        //the size of a cycle(period)
        int cycle = 2 * nRows - 2;
        for(int i = 0; i < nRows; ++i)
        {
            for(int j = i; j < s.length(); j = j + cycle){
               result = result + s[j];
               int secondJ = (j - i) + cycle - i;
               if(i != 0 && i != nRows-1 && secondJ < s.length())
                   result = result + s[secondJ];
            }
        }
        return result;
    }
};





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
