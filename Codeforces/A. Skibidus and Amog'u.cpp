#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string S;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> S;
        S.erase(--S.end());
        S[S.size()-1] = 'i';
        cout << S << endl;
    }
    return 0;
}