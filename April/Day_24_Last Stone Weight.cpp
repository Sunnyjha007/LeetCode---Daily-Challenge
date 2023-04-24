class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first==second){
                if(pq.size()==0)return 0;
                continue;
            }
            if(first>second){
                pq.push(first-second);
            }
        }
        return pq.top();
    }
};
