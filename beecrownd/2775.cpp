#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    while(scanf("%d", &x)!= EOF){
        vector<pair<int,int>>hubi(x);
        for(int i=0; i<x; i++){
            cin>>hubi[i].first;
        }
         for(int i=0; i<x; i++){
            cin>>hubi[i].second;
        }
        // for(int i=0; i<x; i++){
        //     cout << hubi[i].second << " ";
        // }
        int cont  =0;
        for(int i=0 ; i<x-1 ; i++){
            for(int j=0; j<x-i-1; j++){
                if(hubi[j].first>hubi[j+1].first){
                     swap(hubi[j],hubi[j+1]);
                    cont += hubi[j].second + hubi[j+1].second;
                }
            }
        }
        // for(auto i: hubi){
        //     cout << i.first << " "<< i.second << endl;
        // }
        cout << cont << endl;
    }
}   