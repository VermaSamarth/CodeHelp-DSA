#include <iostream>
using namespace std;

// class Physics{
//     public:
//         double physics;
// };

// class Chemistry{
//     public:
//         int chem;
// };

// class Maths: public Physics, public Chemistry{
//     public:
//         float maths;
// };

// int main(){
//     Maths obj;
//     cout << obj.physics << " " << obj.chem << " " << obj.maths << endl;
// }

class Physics{
    public:
        double physics;
        int chem;
        Physics(){
            chem = 1001;
        }
};

class Chemistry{
    public:
        int chem;
        Chemistry(){
            chem = 1002;
        }
};

class Maths: public Physics, public Chemistry{
    public:
        float maths;
};

int main(){
    Maths obj;
    // Ambiguity or Diamond Problem
    // Compiler will get confused. It will not be able to decide whether to return chem from Chemistry or from Physics.
    // cout << obj.physics << " " << obj.chem << " " << obj.maths << endl;
    cout << obj.physics << " " << obj.Chemistry::chem << " " << obj.Physics::chem << " " << obj.maths << endl;

}