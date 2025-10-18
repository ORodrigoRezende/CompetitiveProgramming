#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,n1,n2;
    char c;
    cin >> N;
    cin >> n1 >> c >> n2;
    if(c == '*'){
        if(N>= n1*n2) cout << "OK" << endl;
        else cout << "OVERFLOW" << endl;
    }else if(c == '+'){
        if(N>=n1+n2) cout << "OK" << endl;
        else cout << "OVERFLOW" << endl;
    }

    return 0;
}