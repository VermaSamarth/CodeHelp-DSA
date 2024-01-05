#include <iostream>
using namespace std;

class Fruit{
    public:
        int fruit_No;
};

class Mango: public Fruit{
    public:
        int mango_No;
};

class Alphonso: public Mango{
    public:
        int alphonso_No;
};

int main(){
    Alphonso alp;
    cout << alp.fruit_No << " " << alp.mango_No << " " << alp.alphonso_No << endl;
}