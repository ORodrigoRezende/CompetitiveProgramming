#include <bits/stdc++.h>
using namespace std;

enum{
    pedra, papel, tesoura, lagarto, Spock
};

int converter(string s) {
    if (s == "pedra") return pedra;
    if (s == "papel") return papel;
    if (s == "tesoura") return tesoura;
    if (s == "lagarto") return lagarto;
    if (s == "Spock") return Spock;
    return -1;
}

int main(){
    int T,cont =1;
    vector<set<int>> v(5);
    v[pedra] = {lagarto, tesoura};
    v[papel] = {pedra, Spock};
    v[tesoura] = {papel, lagarto};
    v[lagarto] = {Spock, papel};
    v[Spock] = {pedra, tesoura};
    cin >> T;
    while(T--){
        string s1,s2;
        cin >> s1 >> s2;
        if(s1 == s2){
            cout << "Caso #" << cont << ": De novo!" << endl;
        }else{
            int op1 = converter(s1);
            int op2 = converter(s2);
            if(v[op1].count(op2)){
                cout << "Caso #" << cont << ": Bazinga!" << endl;
            }else if(!v[op1].count(op2)){
                cout << "Caso #" << cont << ": Raj trapaceou!" << endl;
            }
        }
        cont++;
    }
}