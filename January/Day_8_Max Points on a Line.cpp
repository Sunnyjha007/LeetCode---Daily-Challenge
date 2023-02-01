class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
        int n = points.size();
        if(n<=2)return n;
        //sort(points.begin(),points.end());
        for(int i=0;i<n;i++){
            unordered_map<double,int> map;
            int duplicate=0;
            double slope = 0.0;
            for(int j=0;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dy = (y2-y1);
                int dx = (x2-x1);
                if(dy==0&&dx==0){
                    duplicate++;
                    continue;
                }
                if(dx!=0){
                    slope = dy*1.0/dx;
                }else slope = INT_MAX;
                map[slope]++;
            }
            if(map.size()==0)ans = duplicate;
            else{
                for(auto e:map){
                    ans = max(ans,e.second+duplicate);
                }
            }
        }
        return ans;
    }
        
};
