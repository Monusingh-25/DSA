class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            // if interval is the starting or it is not overlapping with other interval
            // ie: we are forming a new interval
            if(ans.empty() || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                // when any interval already lying inside any other interval 
                // update the last element with maximum of coming interval element 
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};