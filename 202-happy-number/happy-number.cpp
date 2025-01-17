class Solution {
    public:
        int jump(int n){
            int sum = 0;
            while(n>0){
                sum += pow(n%10,2);
                n /= 10;
            }
            return sum;
        }

        bool isHappy(int n) {
            int tortoise = jump(n);
            int hare = jump(jump(n));
            while(tortoise!=hare && hare!=1){
                tortoise = jump(tortoise);
                hare = jump(jump(hare));
            }
            return hare==1;
        }
};