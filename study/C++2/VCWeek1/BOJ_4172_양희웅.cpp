#include <iostream>
#include <cmath>

using namespace std;

int x[1000001];

/*
    가우스기호?
*/

int main(void)
{
    int input; 

    x[0] = 1;
    for (int i = 1; i < 1000001; i++) {
        x[i] = (x[(int)floor(i - sqrt(i))] + x[(int)log(i)] + x[(int)(i * sin(i) * sin(i))]) % 1000000;
    }

    while (true) {
        cin >> input;
        if (input == -1) break;
        cout << x[input] << endl; 
    }

    return 0;
}