class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        vector<int> ans;
       
        while(i<n && j<m){
             // when no element is matching
             //element in first array is smaller then second array move pointer forward in first array 
            if(nums1[i]<nums2[j]){
                i++;
            }
            // element in second  array is smaller then first array
            // move pointer of second element forward 
            else if (nums2[j]<nums1[i]){
                j++;
            }
            else{
                  // Ensure unique element is present in the result
            if(ans.empty() || ans.back() != nums1[i]) {
                ans.push_back(nums1[i]);
            }
            i++;
            j++;
        }
     }
     return ans;
 }
};