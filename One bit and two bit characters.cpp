class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // traverse the array age two bit char bn skta h to bna lo ar -1 mark
        // krte jao}}} then after traversal agr last positive to true vrna false

        int n = bits.size();
        for (int i = 0; i < n; i++) {
            if ((i + 1 < n) && ((bits[i] == 1 && bits[i + 1] == 0) ||
                                (bits[i] == 1 && bits[i + 1] == 1))){
                                    bits[i]=bits[i+1]=-1;
                                }
            else{
                continue;
            }
        }
    
        return bits[n-1]==0;
    }
};
