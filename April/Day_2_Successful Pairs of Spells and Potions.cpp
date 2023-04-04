// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         // // spell[i]*each number of potion
//         // int m = spells.size(),n = potions.size(),j=0;
//         // vector<int> ans;
//         // for(int i=0;i<m;i++){
//         //     int cnt=0;
//         //     for(int j=0;j<n;j++){
//         //         long long check =  potions[j]*spells[i];
//         //         if((check)>=success)cnt++;
//         //     }
//         //     ans.push_back(cnt);
//         // }
//         // return ans;
        
//     }
// };
class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        
        vector<int> v(s.size(),0);
        sort(p.begin(),p.end());
        
        for(int i=0;i<s.size();i++)
        {
            int h=p.size()-1;
            int l=0;
            int mid;
            while(l<=h)
            {
                mid = l + (h-l)/2;
                
                if((long long int)s[i]*(long long int)p[mid] >= suc)
                    h = mid-1;
                
                else
                    l = mid+1;
            }
            
            v[i] = p.size()-1-h;
        }
        
        return v;
    }
};
