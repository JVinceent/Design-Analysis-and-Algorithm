#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Combination = vector<int>;       
using ComboList = vector<Combination>; 

ComboList getCombinationsDP(vector<int>& candidates, int target) {
    vector<ComboList> dp(target + 1);
    dp[0].push_back({}); 

    for (int num : candidates) {
        for (int i = num; i <= target; i++) {
            for (Combination combo : dp[i - num]) {
                combo.push_back(num);
                dp[i].push_back(combo);
            }
        }
    }
    return dp[target];
}

int main() {
    int n, target;

    cout << "Enter number of candidates: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    cout << "Enter the target: ";
    cin >> target;
    
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    
    ComboList results = getCombinationsDP(candidates, target);
    sort(results.begin(), results.end());
    
    cout << "Combinations are:\n";
    if (results.empty()) {
        cout << "No combination found.\n";
    } else {
        for (Combination combo : results) {
            cout << "{ ";
            for (int val : combo) {
                cout << val << " ";
            }
            cout << "}\n";
        }
    }
    return 0;
}