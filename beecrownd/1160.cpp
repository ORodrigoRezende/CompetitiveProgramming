#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--){
        int PA,PB,anos=0;
        double G1,G2;
        cin >> PA >> PB >> G1 >> G2;
        while (PA<=PB){
            PA += PA*(G1/100);
            PB += PB*(G2/100);
            anos++;
           //cout << PA << PB << endl;
            if(anos>100){
                cout << "Mais de 1 seculo.\n";
                break;
            } 
        }
        if(anos<=100)cout << anos << " anos." << endl;
    }
    
    return 0;
}