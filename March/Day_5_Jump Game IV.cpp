class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> pn;
        pn.push(0);
        vector<bool> visited(n,false);
        visited[0] = true;
        int cnt = 0;
        while(!pn.empty()){
            int size = pn.size();
            cnt++;
            while(size--){
                int front = pn.front();pn.pop();
                if(front==n-1)return cnt-1;
                if(front-1>=0&&!visited[front-1]){
                    visited[front-1] = true;
                    pn.push(front-1);
                }
                if(front+1>=0&&!visited[front+1]){
                    visited[front+1] = true;
                    pn.push(front+1);
                }
                if(mp.count(arr[front])){
                    for(auto it:mp[arr[front]]){
                        if(it!=front&&!visited[it]){
                            visited[it] = true;
                            pn.push(it);
                        }
                    }
                }
                mp.erase(arr[front]);
            }
        }
        return -1;
    }
};
