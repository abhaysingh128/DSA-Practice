#include<bits/stdc++.h>
using namespace std;
class FenwickTree {
    vector<int> BIT;
    int size;
public:
    FenwickTree(int n) {
        size = n;
        BIT.resize(n + 1, 0);
    }
    
    void update(int index, int delta) {
        while (index <= size) {
            BIT[index] += delta;
            index += index & (-index);
        }
    }
    
    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & (-index);
        }
        return sum;
    }
    
    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    FenwickTree fenwickTree(n);
    
    cout << "Enter elements of the array:\n";
    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        fenwickTree.update(i, value);
    }
    
    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    while (q--) {
        int type;
        cout << "Enter query type (1 for update, 2 for range query): ";
        cin >> type;
        if (type == 1) {
            int index, delta;
            cout << "Enter index and delta: ";
            cin >> index >> delta;
            fenwickTree.update(index, delta);
        } else if (type == 2) {
            int left, right;
            cout << "Enter left and right indices: ";
            cin >> left >> right;
            cout << "Range sum: " << fenwickTree.rangeQuery(left, right) << endl;
        }
    }
    
    return 0;
}