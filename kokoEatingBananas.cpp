class Solution {
public:
    long long timeTaken(vector<int>& piles, int val) {
        long long ans = 0;
        for (auto i : piles) {
            ans +=(i+val-1)/val;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int st = 1;
        int e = piles[piles.size() - 1];
        int ans = -1;
        while (st <= e) {
            int mid = st + (e - st) / 2;
            long long time = timeTaken(piles, mid);
            if (time <= h) {
                ans = mid;
                e = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};
