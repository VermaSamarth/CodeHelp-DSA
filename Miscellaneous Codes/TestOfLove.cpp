#include <bits/stdc++.h>
#include <string>
using namespace std;
#define int long long
int32_t main(){
    int tst;
    cin >> tst;
    while (tst--){
        int a, b, c;
        cin >> a >> b >> c;
        string st;
        cin >> st;

        int crntINd = b - 1;
        int wstpiec = 0, foper = 0;
        for (size_t it = 0; it < st.size(); it++){
            char ch = st[it];
            if (ch == 'L'){
                crntINd = b;
            }
            else if (ch == 'W'){
                if (crntINd <= 0){
                    wstpiec++;
                }
            }
            else{
                if (crntINd <= 0){
                    foper++;
                }
            }
            crntINd--;
        }
        if (wstpiec > c){
            foper++;
        }
        cout << (foper != 0 ? "NO" : "YES") << endl;
    }
    return 0;
}