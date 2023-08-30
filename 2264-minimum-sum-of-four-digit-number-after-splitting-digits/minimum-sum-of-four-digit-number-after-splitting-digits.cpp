class Solution {
public:
    int minimumSum(int num) {
        int s[4] = {};
        for(int i=0;i<4;++i,num/=10)
            s[i]=num%10;
        sort(begin(s),end(s));
        return 10*(s[0]+s[1])+s[2]+s[3];
    }
};