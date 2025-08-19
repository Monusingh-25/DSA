class Solution {
public:
    int maximum69Number (int num) {
        vector<int>ds;
        // converting  number in  array of digits  
        while(num>0){
            ds.push_back(num%10);
            num/=10;
        }
        reverse(ds.begin(),ds.end());
        for(int i=0;i<ds.size();i++){
            if(ds[i]==6){
                ds[i]=9;
                break;   
            } 
        }
        // creating number from the elements of vector 
        int ans=0;
        for(auto it : ds){
            ans=ans*10+it;
        }
        return ans;
    }

};

            

           

            
                   






