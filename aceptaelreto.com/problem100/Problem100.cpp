//============================================================================
// Author       : Rafael J. Vicente
// E-mail       : rafaelj.vicente@gmail.com
// Version      : 1.0
// Copyright    : All rights reserved
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Main function
 */
int main()
{
  int n_numbers;
  cin >> n_numbers;

  for (int i = 0; i < n_numbers; ++i)
  {
    int iteration = 0, x;
    cin >> x;

    while (x != 0 && x != 6174)
    {
      // Iteration++
      ++iteration;

      vector<unsigned char> n;
      for (int i = 0; i < 4; i++)
      {
        n.push_back(x % 10);
        x /= 10;
      }

      // Order
      sort(n.begin(), n.end());

      const int a = n[3] * 1000 + n[2] * 100 + n[1] * 10 + n[0];
      const int b = n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3];
      x = a - b;
    }

    // Repdigits (1111,2222, etc.)
    if (x == 0)
      iteration = 8;

    // Print iteration number
    cout << iteration << endl;
  }

  return 0;
}

