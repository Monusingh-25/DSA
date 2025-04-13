class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
          int n=nums.size();
        if(n==0) return 0;
        int longest=1;
        unordered_set<int>st;
        // insert all unique element in the set 
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        // iterate in the set and check are you the first element of sequence 
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int element=it;
                while(st.find(element+1)!=st.end()){
                    element+=1;
                    count+=1;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};