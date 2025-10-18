#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n; cin >> n;

    vector<tuple<ll, ll, ll, string>> med;
    while (n--){
        string s; cin >> s;
        ll a, b, c; cin >> a >> b >> c;
        med.push_back(make_tuple(-a, -b, -c, s)); 
    }

    sort(med.begin(), med.end());

    for (int m = 0; m < med.size(); m++){
        cout << get<3>(med[m]) << " " << -get<0>(med[m]) << " " << -get<1>(med[m])<< " " << -get<2>(med[m]) << "\n";
    }   
    return 0;
}