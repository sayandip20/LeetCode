class Solution {
public:
    bool check(vector<int>& nums, int threshold, int divisor){
        int val = 0;
        for(int i = 0; i < nums.size(); i++){
            val += ceil((double)(nums[i]) / (double)(divisor));
        }
        return val <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        if (nums.size() > threshold) return -1;
        int low = 1;
        int high = maxi;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(nums, threshold, mid)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};