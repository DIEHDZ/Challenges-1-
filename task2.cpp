#include <iostream>

using namespace std;

int main() {
    float a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a+b << endl
         << a << " - " << b << " = " << a-b << endl
         << a << " * " << b << " = " << a*b << endl;
         
    if (b == 0)
    cout << a << " / " << b << " = " << "undefined" << endl;
    else
    cout << a << " / " << b << " = " << a/b << endl;

   

    return 0;
}