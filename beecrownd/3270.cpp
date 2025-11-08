#include <bits/stdc++.h>
using namespace std;

int main(){
    int C,n,atual=0,ok=1;
    cin >> C >> n;
    while (n--){
        int S,E,Es;
        cin >> S >> E >> Es;
        if(S>atual){
            ok = 0;
        }
        atual = atual - S;
        if(E>C-atual){
            ok=0;
        }
        atual += E;
        
        if(0 < C-atual && Es!=0 ){
            ok = 0;
            //cout << "aq" << C-atual << Es;
        }
        if(n==0){
            if(Es!=0) ok = 0;
            if(atual>0) ok = 0;
        } 
    }
    if(ok) cout << "possible" << endl;
    else cout << "impossible" << endl;
    

    return 0;
}