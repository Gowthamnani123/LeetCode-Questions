class Solution {
public:
    int mySqrt(int x) {
  long i = 0;
    while(true){
        if(x < (i+1)*(i+1))
            return i;
        ++i;
    }
        return 1;
    }
};