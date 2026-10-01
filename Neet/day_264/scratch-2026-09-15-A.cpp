#include <iostream>
using namespace std;

int main() 
{
    cout << "Enter an integer" << endl;

    int x;
    cin >> x;
    cout << ((x % 2 == 0) ? "odd" : "even") << endl;
};
