// class Solution {
// public:
//     long long distinctNames(vector<string>& ideas) {
//         int n = ideas.size();
//         unordered_map<string,int> mp;
//         for(int i=0;i<n;i++)mp[ideas[i]]=1;
//         long long ans = 0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 string a = ideas[i];
//                 string b = ideas[j];
//                 char temp = a[0];
//                 a[0] = b[0];
//                 b[0] = temp;
//                 if(mp.count(a)==0&&mp.count(b)==0)ans++;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        unordered_map<char,unordered_map<string,int>> mp;
        for(int i=0;i<n;i++)mp[ideas[i][0]].insert({ideas[i].substr(1,ideas[i].size()-1),1});
        long long ans = 0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                unordered_map<string,int> a = mp[i+'a'],b = mp[j+'a'];
                int common = 0;
                for(auto it:a){
                    if(b.find(it.first)!=b.end())common++;
                }
                ans+= (long long)(a.size()-common)*(long long )(b.size()-common)*2;
            }
        }
        return ans;
    }
};

