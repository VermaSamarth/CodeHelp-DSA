#include <iostream>
using namespace std;

int slow(int a, int b)
{
    int ans = 1;
    for (int i = 1; i <= b; i++)
    {
        ans = ans * a;
    }
    return ans;
}

int fast(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = ans * a;
        }
        a = a * a;
        b = b / 2;
    }
    return ans;
}

int main()
{
    int num1, num2;
    cout << "Enter the numbers: " << endl;
    cin >> num1 >> num2;
    cout << "Slow Exponentiation: " << slow(num1, num2) << endl;
    cout << "Fast Exponentiation: " << fast(num1, num2) << endl;
    return 0;
}