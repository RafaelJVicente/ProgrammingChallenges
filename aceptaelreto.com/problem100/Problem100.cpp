//============================================================================
// Author       : Rafael J. Vicente
// E-mail       : rafaelj.vicente@gmail.com
// Version      : 1.1
// Copyright    : All rights reserved
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Main function
 */
int main()
{
  const int KAPREKAR = 6174;
  const int MAX_S = 4;

  int n_numbers;
  cin >> n_numbers;

  for (int i = 0; i < n_numbers; ++i)
  {
    int num;
    cin >> num;

    int arr[MAX_S];
    int iteration = 0;
    while (num != 0 && num != KAPREKAR)
    {
      // Iteration++
      ++iteration;

      // Load number in array
      for (int j = MAX_S - 1; j >= 0; --j)
      {
        const auto tmp = div(num, 10);
        arr[j] = tmp.rem;
        num = tmp.quot;
      }

      // Order
      sort(arr, arr + MAX_S);

      // Inverse - ordered (ex.: 4321-1234)
      num = 999 * arr[3] + 90 * arr[2] - 90 * arr[1] - 999 * arr[0];
    }

    // Print iteration number or 8 to indicate Repdigits (1111,2222, etc.)
    cout << (num ? iteration : 8) << endl;
  }

  return 0;
}

