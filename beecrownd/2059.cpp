#include <bits/stdc++.h>
using namespace std;

int main(void){
    int p, j1, j2, r, a;
    cin >> p >> j1 >> j2 >> r >> a;
    int t = j1+j2;
    if((r&&!a) || (!r&&a)){
        cout << "Jogador 1 ganha!\n";
    }else if((r&&a)){
        cout << "Jogador 2 ganha!\n";
    }else if((p==1 && (t%2==0)) || (p==0 && (t%2!=0))){
        cout << "Jogador 1 ganha!\n";
    }else{
        cout << "Jogador 2 ganha!\n";
    }

    return 0;
}