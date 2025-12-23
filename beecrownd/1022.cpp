#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mdc(int a, int b){
    return b == 0 ? abs(a) : mdc(b, a % b);
}

int main(){
    int n;
    cin >> n;
    while (n--){
        int N1, D1, N2, D2, R1, R2;
        char c,a,b;
        scanf("%d %c %d %c %d %c %d",&N1,&a,&D1,&c,&N2,&b,&D2);
        switch (c)
        {
        case '+':
            R1= (N1*D2 + N2*D1) ;
            R2 = (D1*D2);
            break;
        case '-':
            R1= (N1*D2 - N2*D1) ;
            R2=(D1*D2);
            break;
        case '*':
            R1 = (N1*N2) ;
            R2 = (D1*D2);
            break;
        case '/':
            R1 = (N1*D2);
            R2 = (N2*D1);
            break;
        default:
            break;
        }
        int div = mdc(R1,R2);
        if(R2 < 0){
            R1 = -R1;
            R2 = -R2;
        }
        cout << R1<< "/"<<R2<< " = " << R1/div << "/" << R2/div << endl;
            
    }
    
    
}