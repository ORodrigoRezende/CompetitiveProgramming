#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll coun = 0;


ll fib(ll x){
    ++coun;
    if (x == 0){
        return 0;
    }
    if (x == 1){
        return 1;
    }
    return fib(x-1) + fib(x-2);
}
    

int main(){
    ll N; cin >> N;

    while (N--){
        coun = 0;
        ll x; cin >> x;
        ll a = fib(x);
        printf("fib(%ld) = %ld calls = %ld\n", x, coun-1, a);
    }

    return 0;
}