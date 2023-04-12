class Solution {
public:
    int help(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}
    bool isHappy(int n) {
        int fast = n, slow = n;
        do{
            slow = help(slow);
            fast = help(fast);
            fast = help(fast);
            cout<<slow<<" "<<fast<<endl;
        }while(fast != slow);
        if(slow == 1) return true;
        return false;
    }
};