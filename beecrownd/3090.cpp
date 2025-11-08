#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,m,s;
    cin >> n >> m >> s;
    ll poder1=0,poder2=0;
    double div = (double)m/(double)n;
    for (int i = 0; i < s; i++){
        double x,y;
        ll h;
        cin >> x >> y >> h;
       if(y> div*x){
        poder1+= h;
       }
       else{
        poder2+= h;
       }
    }
    cout << poder1 << " " << poder2 << endl;
    


    return 0;
}