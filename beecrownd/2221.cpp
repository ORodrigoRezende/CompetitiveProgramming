#include <bits/stdc++.h>
using namespace std;

int main(void){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int B,AID,DID,LID,AIG,DIG,LIG;
        cin >> B;
        cin >> AID >> DID >> LID;
        cin >> AIG >> DIG >> LIG;
        double D,G;
        D = (AID + DID)/ 2;
        G = (AIG + DIG)/ 2;
        if(LID %2==0) D += B;
        if(LIG %2==0) G += B;
        if(G>D){
            printf("Guarte\n");
        }else if(D>G){
            printf("Dabriel\n");
        }else{
            printf("Empate\n");
        }
    }
    

    return 0;
}