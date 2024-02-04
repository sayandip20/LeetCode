class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return 0;
        int sum = 0;
        int maxi = INT_MIN;
        for(auto it : arr){
            sum+=it;
            maxi = max(sum,maxi);
            if(sum<0) sum=0;
        }
        return maxi;
    }
};