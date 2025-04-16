class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    // increse sum so go right as array is sorted in increasing order 
                    j++;
                }
                else if(sum>0){
                    // go to left as we have to decrease the given sum 
                    k--;
                }
                else{
                    // if sum==0 then store those numbers in an additional data structure 
                    vector<int> temp={nums[i],nums[j],nums[k]};
                            ans.push_back(temp);
                            j++;
                            k--;
                            while(j<k && nums[j]==nums[j-1]) j++;
                            while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};