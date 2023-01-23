class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n+1, 0);
        
        for(auto t : trust){
            degree[t[0]]--; //outdegree of a node
            degree[t[1]]++; //indegree of a node
        }
        for(int i=1; i<=n; i++){  
            if(degree[i]==n-1) return i;
        }
        return -1;
    }
};
//The town judge trusts nobody.
//Everybody (except for the town judge) trusts the town judge.
