#include <bits/stdc++.h>
using namespace std;

int main(void){
    int x;
    cin >> x;
    for (int i = 0; i < x; i++){
        string s;
        cin >> s;
        for (int i = s.size(); i >= 0; i--)
        {
            if(islower(s[i])){
                cout << s[i];
            }
        }
        cout << "\n";
    }
}