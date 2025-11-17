class Solution {
public:
    int binarySearch(int el,vector<int>& potions,long long success){
     int st=0;
     int e=potions.size()-1;
     int ans=-1;
     while(st<=e){
        int mid=st+(e-st)/2;
        long long val=1LL*el*potions[mid];
        if(val>=success){
            ans=mid;
            e=mid-1;
        }
        else{
            st=mid+1;
        }
     }
     return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       sort(potions.begin(),potions.end());
       vector<int> res;
       for(auto i:spells){
        int correctPotionIndex=binarySearch(i,potions,success);
        int val=potions.size()-correctPotionIndex;
        correctPotionIndex==-1?res.push_back(0): res.push_back(val);
         
          
       } 
       return res;
    }
};
