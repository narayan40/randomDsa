class Solution {
public:
   bool isPower(int n,int x,int t){
    if(pow(x,t)==n){
        return true;
    }
    if(pow(x,t)>n){
        return false;
    }
   return  isPower(n,x,t+1);
   }
    bool isPowerOfFour(int n) {
    
        return isPower(n,4,0);
    }
};
