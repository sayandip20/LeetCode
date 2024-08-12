class Solution {
public:
    int maxele(vector<int>& piles, int n){
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long func(vector<int>& piles, int k, int n){
        long long totalH = 0;
        for(int i = 0; i < n; i++){
            totalH += ceil((double)(piles[i])/ (double)(k));
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = maxele(piles, n);
        int ans = 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalH = func(piles, mid, n);
            if(totalH <= h){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};