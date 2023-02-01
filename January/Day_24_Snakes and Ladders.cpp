class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int destination = n*n;
        unordered_map<int,int> mp;
        mp[1] = 0;
        queue<int> pn;
        pn.push(1);
        while(!pn.empty()){
            auto front = pn.front();pn.pop();
            for(int i=1;i<=6;i++){
                int next = front + i;
                if(next>destination)break;
                int row = (next-1)/n;
                int col = (row%2==0)?(next-1)%n:n-1-((next-1)%n);
                if(board[n-1-row][col]!=-1){
                    next = board[n-1-row][col];
                }
                if(mp.count(next)==0){
                    mp[next] = mp[front]+1;
                    if(next==destination){return mp[next];}
                    pn.push(next);
                }
            }
        }
        return -1;
    }
};
