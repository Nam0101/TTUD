#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> coins = {100, 25, 10, 5, 1};

void find_minimum_coins(int amount) {
    int n = coins.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        int numCoins = amount / coins[i];
        count += numCoins;
        amount -= numCoins * coins[i];
    }
    cout << "Minimum number of coins needed: " << count << endl;
}

int main() {
    int amount;
    cout << "Enter amount in cents: ";
    cin >> amount;
    find_minimum_coins(amount);
    return 0;
}
