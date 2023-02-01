class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.size(),n = str2.size();
        if(m<n)return gcdOfStrings(str2,str1);
        if(n==0)return str1;
        if(str1.substr(0,n)!=str2)return "";
        return gcdOfStrings(str1.substr(n),str2);
        
    }
};
