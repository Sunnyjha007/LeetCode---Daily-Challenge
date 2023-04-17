class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0, n = pushed.size();
        for (auto a : pushed) {
            s.push(a);
            while (!s.empty() && s.top() == popped[i]) {
                s.pop();
                i++;
            }
        }   
        return i == n;
    }
};
