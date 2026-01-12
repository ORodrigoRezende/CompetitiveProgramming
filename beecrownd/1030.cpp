#include <bits/stdc++.h>
using namespace std;

int main(){
    int NC,cont=1;
    cin >> NC;
    while(NC--){
        int n,k;
        cin >> n >> k;
        vector<pair<int,int>> grupo;
        for (int i = 0; i < n; i++){
            grupo.push_back({i,i+1});
        }
        int atual = 0 ;
        while (grupo.size() > 1 ){
            atual = (atual+k-1) % grupo.size();
            grupo.erase(grupo.begin()+atual);
        }
        cout << "Case " << cont << ": " << grupo[0].second << endl;
        cont ++;
    }
}