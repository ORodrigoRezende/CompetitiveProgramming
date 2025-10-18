#include <bits/stdc++.h>
using namespace std;
#define ll long long

string comp = "<body>";
string comp2 = "</body>";


int verificaInicio(string s){
    int v=0;
    int i;
    for(i=0;i<s.size() && v<6;i++){
        if(s[i]==comp[v]){
            v++;
        }else{
            v=0;
        }
    }
    if(v==6){
        return 1;
    }else{
        return 0;
    }
}
int verificaFim(string s){
    int v=0;
    int i;
    for(i=0;i<s.size() && v<7;i++){
        if(s[i]==comp2[v]){
            v++;
        }else{
            v=0;
        }
    }
    if(v==7){
        return 1;
    }else{
        return 0;
    }
}


int main(){
    string s;
    int ini = 0;
    while(getline(cin, s)){
        if(verificaInicio(s)){
             ini =1;
        }
        else if(verificaFim(s)==0 && ini){
            cout << s << endl;
        }
        else if(verificaFim(s)) ini = 0;
    }
    return 0;
}