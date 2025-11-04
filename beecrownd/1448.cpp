#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,cont3=1;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string original;
        string primeira;
        string segunda;
        int x[2] = {-1,-1},prim=1,cont1=0,cont2=0,prim2 = 1;;
        getline(cin,original);
        getline(cin,primeira);
        getline(cin,segunda);
        int n = min({original.size(), primeira.size(), segunda.size()});
        for(int i =0 ;i<n;i++){
            if(original[i]==primeira[i]){
                cont1++;
                x[0] = i;
            }
            if(original[i]==segunda[i]){
                cont2++;
                x[1] = i;
            }
            
        }
        
        cout << "Instancia " << cont3 << endl;
        cont3++;
        // cout << original << endl<< primeira << endl<< segunda << endl;
        // cout << cont1 << " "<< cont2 << " "<< x[0] << " "<< x[1] << " " << primeira.size() <<" " << segunda.size()<<endl;
        if(cont1>cont2){
            cout << "time 1" << endl;
        }else if(cont2> cont1){
            cout << "time 2" << endl;
        }else{
            if(x[0]>x[1]){
            cout << "time 1" << endl;
            }else if(x[1]>x[0]){
                cout << "time 2" << endl;
            }else{
                cout << "empate" << endl;
            }
        }
        if(t!=0)
        cout << endl;
    }
    
}