//============================================================================
// Author       : Rafael J. Vicente
// E-mail       : rafaelj.vicente@gmail.com
// Version      : 1.0
// Copyright    : All rights reserved
//============================================================================

#include <iostream>

using namespace std;

void read_int(int &number)
{
    register int c;
    number = 0;
    c = getchar();

    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
}

/**
 * Main function
 */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;

    for (; read_int(x), !(x== 0);)
    {
    }
    cout << "\n";

    return 0;
}
