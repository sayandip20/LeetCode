class Solution {
    public int balancedStringSplit(String s) {
        int balanced = 0;
        int sum = 0;
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(c=='R') balanced++;
            if(c=='L') balanced--;
            if(balanced==0) sum++;
        }
        return sum;
    }
}