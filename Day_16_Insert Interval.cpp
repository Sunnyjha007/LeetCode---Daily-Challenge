class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
            }else if(intervals[i][0]>newInterval[1]){
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }else if(intervals[i][1]>=newInterval[0]||intervals[i][0]<=newInterval[1]){
                newInterval[0] = min(intervals[i][0],newInterval[0]);
                newInterval[1] = max(intervals[i][1],newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};
/*
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[j][1]>=intervals[i][0]){
                intervals[j][1] = max(intervals[j][1],intervals[i][1]);
            }else{
                j++;
                intervals[j] = intervals[i];
            }
        }
        intervals.resize(j+1);
        return intervals;
    }
};
*/
