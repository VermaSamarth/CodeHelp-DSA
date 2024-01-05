#include<iostream>
using namespace std;

// Example to function overloading (Compile-Time Polymorphism)
class Maths{
    public:
        int sum(int a, int b){
            return a + b;
        }

        int sum(int a, int b, int c){
            return a + b + c;
        }

        float sum(int a ,float b){
            return a + b;
        }
};

int main(){
    Maths solve;
    cout << solve.sum(10,20) << endl;
    cout << solve.sum(10,20,30) << endl;
    cout << solve.sum(10,25.5f) << endl;
}