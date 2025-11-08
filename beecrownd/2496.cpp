#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        string s;
        cin >> s;
        vector<pair<int,char>> errados;
        for (int i = 0; i < s.size(); i++){
            if(s[i]-'A' != i){
                errados.push_back({i,s[i]});
            }
        }
        if(errados.size()==2){
            if((errados[0].second -'A')== errados[1].first && (errados[1].second -'A')== errados[0].first){
                cout << "There are the chance.\n";
            }else{
                cout << "There aren't the chance.\n";
            }
        }else{
            cout << "There aren't the chance.\n";
        }
    }


    return 0;
}