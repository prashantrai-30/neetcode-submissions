class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        int i = 31;
        while(i > 0) {
            int d = n%2;
            if(d == 1) cnt++;
            n/=2;
            i--;
        }
        return cnt;

    }
};
