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

int segment_count(int n, string &str) {
    int segments = 0;
    bool issegment = false;

    for (int i = 1; i < n; i++) {
        if (str[i] == ')' && str[i-1] == '(') {
            if (!issegment) {
                segments++;      
                issegment = true;
            }
            i++; 
        } else {
            issegment = false; 
        }
    }
    return segments;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int count_os = 0, count_ot = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') count_os++;
        if(t[i] == '(') count_ot++;
    }

    if(count_os != count_ot) {
        cout << "NO" << '\n';
        return;
    }

    int zero_s = 0, zero_t = 0;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '(' && s[i+1] == ')') {
            zero_s++;
            i++; 
        }
    }
    for(int i = 0; i < n - 1; i++) {
        if(t[i] == '(' && t[i+1] == ')') {
            zero_t++;
            i++; 
        }
    }

    if(zero_s != zero_t) {
        cout << "NO" << '\n';
        return;
    } 

    int segs = segment_count(n, s);
    int segt = segment_count(n, t);

    if(segs == segt) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    fast_io;
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}