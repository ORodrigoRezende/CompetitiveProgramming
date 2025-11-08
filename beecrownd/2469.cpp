#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int,int> notas;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        notas[temp]++;
    }
    int maior=0,ind=-1;
    for(auto i: notas){
        if(i.second>maior){
            maior = i.second;
            ind = i.first;
        }else if(i.second == maior){
            if(ind<i.first)
            ind = i.first;
        }
    }
    cout << ind << endl;

    return 0;
}