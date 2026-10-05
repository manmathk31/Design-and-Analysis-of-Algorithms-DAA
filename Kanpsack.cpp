#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int value[n], weight[n];
    double ratio[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> value[i] >> weight[i];

        ratio[i] = (double)value[i] / weight[i];
    }

    cout << "Enter capacity: ";
    cin >> capacity;

    cout << "\nValue-to-Weight Ratio:\n";

    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " : "
             << ratio[i] << endl;
    }

   
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(value[i], value[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    cout << "\nItems after sorting by ratio:\n";

    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1
             << " -> Value = " << value[i]
             << ", Weight = " << weight[i]
             << ", Ratio = " << ratio[i] << endl;
    }

    double ans = 0;

    for (int i = 0; i < n; i++) {

        if (capacity >= weight[i]) {
            capacity -= weight[i];
            ans += value[i];
        }
        else {
            ans += ratio[i] * capacity;
            break;
        }
    }

    cout << "\nMaximum Value = " << ans << endl;

    cout << "Time Complexity = O(n^2)" << endl;

    return 0;
}