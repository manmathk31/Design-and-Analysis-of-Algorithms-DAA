
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), profit(n);

    cout << "Enter weight and profit of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> weight[i] >> profit[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                int take = profit[i - 1] + dp[i - 1][w - weight[i - 1]];
                int notTake = dp[i - 1][w];

                dp[i][w] = max(take, notTake);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nDP Table:\n";
    cout << setw(8) << "Item/W";

    for (int w = 0; w <= capacity; w++) {
        cout << setw(5) << w;
    }
    cout << "\n";

    for (int i = 0; i <= n; i++) {
        cout << setw(8) << i;
        for (int w = 0; w <= capacity; w++) {
            cout << setw(5) << dp[i][w];
        }
        cout << "\n";
    }

    int w = capacity;
    int totalWeight = 0;
    int totalProfit = 0;

    cout << "\nSelected Items (Backtracking):\n";

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i
                 << " (Weight: " << weight[i - 1]
                 << ", Profit: " << profit[i - 1] << ")\n";

            totalWeight += weight[i - 1];
            totalProfit += profit[i - 1];
            w -= weight[i - 1];
        }
    }

    cout << "\nMaximum Profit: " << dp[n][capacity];
    cout << "\nTotal Weight: " << totalWeight << " kg";
    cout << "\nTotal Profit: " << totalProfit << "\n";

    return 0;
}