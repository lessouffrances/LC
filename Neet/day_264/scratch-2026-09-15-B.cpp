#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    cout << "Enter three words" << endl;
    string s1, s2, s3;
    vector<string> strs;

    cin >> s1;
    cout << "First one!" << endl;
    strs.push_back(s1);

    cin >> s2;
    cout << "Second one!" << endl;
    strs.push_back(s2);

    cin >> s3;
    cout << "Third one!" << endl;
    strs.push_back(s3);

    sort(strs.begin(), strs.end());

    for (auto& str : strs) {
        cout << str << " ";
    }
    cout << endl;
}