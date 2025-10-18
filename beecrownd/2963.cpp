#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n; cin >> n;
    vector<pair<ll, ll>> e(n);

    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        e[i] = {a, -(i+1)};
    }
    sort(e.begin(), e.end());
    if (e[n-1].second == -1){
        cout << "S\n";
    }
    else{
        cout << "N\n";
    }
    return 0;
}