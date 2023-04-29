class Solution {
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    int find_prnt(int node, vector<int> &prnt) {
        if(node == prnt[node]) return node;
        return prnt[node] = find_prnt(prnt[node], prnt);
    }
    void unionn(int u, int v, vector<int> &prnt, vector<int> &rank) {
        int ulp_u = find_prnt(u, prnt), ulp_v = find_prnt(v, prnt);

        if(rank[ulp_u] > rank[ulp_v]) prnt[ulp_v] = ulp_u; 
        else if(rank[ulp_u] < rank[ulp_v]) prnt[ulp_u] = ulp_v;
        else {
            prnt[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = queries.size(), p = 0;
        for(int i=0; i<m; i++) queries[i].push_back(i);

        sort(edgeList.begin(), edgeList.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);

        vector<bool> ans(m);
        vector<int> prnt(n), rank(n);
        for(int i=0; i<n; i++) prnt[i] = i;

        for(auto q : queries) {
            while(p < edgeList.size() && edgeList[p][2] < q[2]) {
                unionn(edgeList[p][0], edgeList[p][1], prnt, rank), p++;
            }
            ans[q[3]] = find_prnt(q[0], prnt) == find_prnt(q[1], prnt);
        }
        return ans;
    }
};
