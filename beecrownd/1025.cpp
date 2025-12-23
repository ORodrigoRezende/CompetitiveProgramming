#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Q,vezes=1;
    cin >> N >> Q;
    while(N!=0 && Q!=0){
        vector<int> mapa;
        int achou=0;
        for (int i = 0; i < N; i++){
            int x;
            cin >> x;
            mapa.push_back(x);
        }
        sort(mapa.begin(),mapa.end());
        cout << "CASE# " << vezes <<":" << endl;
        for(int i=0;i<Q;i++){
            int y;
            cin >> y;
            auto it = lower_bound(mapa.begin(),mapa.end(),y);
            if(it != mapa.end() && *it == y){
                cout << y << " found at " << (it - mapa.begin()+1) << endl;
            }else{
                cout << y <<" not found" << endl;
            }
        }
        vezes++;
        cin >> N >> Q;
    }
}