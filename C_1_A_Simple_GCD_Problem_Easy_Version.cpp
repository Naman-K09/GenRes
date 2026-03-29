#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define error cout << "Hare Krishna" << endl;

// PBDS Ordered Set: s.find_by_order(k), s.order_of_key(x)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    int gcd = a[0];
    int count1 = 0;
    if(a[0] == 1) count1++;
    for(int i = 1; i < n; i++) {
        if(a[i] == 1) count1++;
        gcd = __gcd(gcd, a[i]);
    }
    
    sort(a.begin(), a.end());
    
    if(gcd == 1) {
        cout << n - count1 << '\n';
    }
    else if(gcd != a[0]) {
        cout << 2 << '\n';
    }
    else if(gcd == a[0]) {
        if(gcd == a[1]) {
            cout << 0 << '\n';
        }
        else cout << 1 << '\n';
    }
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}