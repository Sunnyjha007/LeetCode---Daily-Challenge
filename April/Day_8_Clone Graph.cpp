/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    // Node* dfs(Node* node,unordered_map<Node*,Node*>& map){
    //     vector<Node*> neighbor;
    //     Node* clone = new Node(node->val);
    //     map[node] = clone;
    //     for(auto i:node->neighbors){
    //         if(map.find(i)!=map.end()){
    //             neighbor.push_back(map[i]);
    //         }else{
    //             neighbor.push_back(dfs(i,map));
    //         }
    //     }
    //     clone->neighbors = neighbor;
    //     return clone;
    // }
public:
    Node* cloneGraph(Node* node) {
        // unordered_map<Node*,Node*> map;
        // if(node==NULL)return node;
        // if(node->neighbors.size()==0){
        //     Node* clone = new Node(node->val);
        //     return clone;
        // }
        // return dfs(node,map);
        if(!node)return node;
        unordered_map<Node*,Node*> visited;
        queue<Node*> pn;
        pn.push(node);
        visited[node] = new Node(node->val);
        while(!pn.empty()){
            auto front = pn.front();pn.pop();
            for(auto e:front->neighbors){
                if(!visited[e]){
                    visited[e] = new Node(e->val);
                    pn.push(e);
                }
                visited[front]->neighbors.push_back(visited[e]);
            }
        }
        return visited[node];
    }
};
