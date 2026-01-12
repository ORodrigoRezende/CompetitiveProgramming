#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    unordered_map<int,int> leds{(0,1)};
    leds[0] = 6;
    leds[1] = 2;
    leds[2] = 5;
    leds[3] = 5;
    leds[4] = 4;
    leds[5] = 5;
    leds[6] = 6;
    leds[7] = 3;
    leds[8] = 7;
    leds[9] = 6;
    while(N--){
        string V;
        cin >> V;
        int R = 0;
        for (int i = 0; i < V.size(); i++){
            R += leds[V[i]-'0'];
        }
        cout << R << " leds" << endl;
    }
}