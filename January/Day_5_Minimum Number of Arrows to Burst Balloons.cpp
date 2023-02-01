class Solution {
public:
static bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int j=0,n=points.size();
        for(int i=1;i<n;i++){
            if(points[j][1]<points[i][0]){
                j++;
                points[j] = points[i];
            }
        }
        return j+1 ;
    }
};
