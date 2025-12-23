#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,k=1;
    cin >> n;
    while (n!=0){
        string s1,s2;
        cin >> s1 >> s2;
        cout << "Teste " << k << endl;
        k++;
        while (n--){
        int a,b;
        cin >> a >> b;
        if((a+b)%2==0)
            cout << s1 << endl;
        else
            cout << s2 << endl;
        }
        cout << endl;
        cin >> n;
    }
    
    return 0;
}