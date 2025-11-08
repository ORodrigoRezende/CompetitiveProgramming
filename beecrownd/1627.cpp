#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int At, Ad, Bt ,Bd,H;
        cin >> At >> Ad >> Bt >> Bd;
        cin >> H;
        int vencedor,t1=Ad,t2=Bd;
        H-= At;
        if(H<=0){
            cout << "Andre" << endl;
            continue;
        }
        H-= Bt;
        if(H<=0){
            cout << "Beto" << endl;
            continue;
        }
        while(H>0){
            if(t1<=t2){
                H-=At;
                t1+= Ad;
                vencedor = 0;
            }else{
                H-=Bt;
                t2+=Bd;
                vencedor = 1;
            }
        }
        cout << (vencedor ? "Beto": "Andre") << endl;
    }
}