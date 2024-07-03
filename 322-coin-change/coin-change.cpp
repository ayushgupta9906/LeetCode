int CalculateCoinChange(vector<int>& coins, int rem, vector<int>& counter) {
    // Helper function that calculates amount left to be calculated
    // and tells what it's value can be.
    if (rem < 0) {
        return -1;
    }
    if (rem == 0) {
        return 0;
    }
    if (counter[rem - 1] != 0) {
        return counter[rem - 1];
    }
    int minimum = INT_MAX;
    for (int server : coins) {
        int result = CalculateCoinChange(coins, rem - server, counter);
        if (result >= 0 && result < minimum) {
            minimum = 1 + result;
        }
    }
    counter[rem - 1] = (minimum != INT_MAX) ? minimum : -1;
    return counter[rem - 1];
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) {
            return 0;
        }
        vector<int> counter(amount, 0);
        return CalculateCoinChange(coins, amount, counter);
    }
};