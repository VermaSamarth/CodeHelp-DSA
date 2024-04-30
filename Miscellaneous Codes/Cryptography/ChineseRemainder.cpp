#include<iostream>
using namespace std;

int calculateInverse(int num1, int num2){
    int init_num = num1;
        int quo, res, y1 = 0, y2 = 0, y = 1;
        while(num1 != 1 && num2 != 0){
            y1 = y2;
            y2 = y;
            quo = num1 / num2;
            res = num1 % num2;
            y = y1 - (y2 * quo);
            num1 = num2;
            num2 = res;
        }
        if(y2 < 0)
            y2 = init_num + y2;
        return y2;
}

int main(){
    int a1, a2, a3, m1, m2, m3;
    cout << "Enter the Values for the three equations. " << endl;
    cout << "Equation 1: ";
    cin >> a1 >> m1; 
    cout << "Equation 2: ";
    cin >> a2 >> m2;
    cout << "Equation 3: ";
    cin >> a3 >> m3;

    // Calculating the value of M
    int M = m1 * m2 * m3;

    // Calculating M1, M2 & M3
    int M1 = M / m1;
    int M2 = M / m2;
    int M3 = M / m3;

    // Calculating the inverse M1, M2 & M3.
    int inv_M1 = calculateInverse(m1, M1);
    int inv_M2 = calculateInverse(m2, M2);
    int inv_M3 = calculateInverse(m3, M3);

    cout << endl << "Value of M = " << M << endl;
    cout << "M1 = " << M1 << endl;
    cout << "M2 = " << M2 << endl;
    cout << "M3 = " << M3 << endl;
    cout << endl << "Inverse M1 = " << inv_M1 << endl;
    cout << "Inverse M2 = " << inv_M2 << endl;
    cout << "Inverse M3 = " << inv_M3 << endl;

    int ans = ((a1 * M1 * inv_M1) + (a2 * M2 * inv_M2) + (a3 * M3 * inv_M3)) % M;
    // cout << "X = " << ((a1 * M1 * inv_M1) + (a2 * M2 * inv_M2) + (a3 * M3 * inv_M3)) << endl;
    cout << endl << "Answer = " << ans << endl;
}
