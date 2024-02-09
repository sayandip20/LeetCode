class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n,0);
        int pos=0, neg=1;
        for(int i = 0; i < n; i++){
            if(a[i]<0){
                ans[neg] = a[i];
                neg+=2;
            }
            else{
                ans[pos] = a[i];
                pos+=2;
            }
        }
        return ans;
    }
};