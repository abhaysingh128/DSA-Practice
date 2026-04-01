#include<bits/stdc++.h>
using namespace std;
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int>f;
    f[0] = 1; // There's one way to have a sum of 0 (empty subarray)
    int prefixSum = 0;
    int result = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        int mod = ((prefixSum % k) + k) % k; // Handle negative mods

        if (f.find(mod) != f.end()) {
            result += f[mod];
        }
        f[mod]++;
    }

    return result;
}
int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << "Number of subarrays divisible by " << k << ": " << subarraysDivByK(nums, k) << endl;
    return 0;
}