//============================================================================
// Author       : Rafael J. Vicente
// E-mail       : rafaelj.vicente@gmail.com
// Version      : 1.2
// Copyright    : All rights reserved
//============================================================================

#include <iostream>
#include <algorithm>
#include <memory>
#include <thread>

using namespace std;

/**
 * Thread function
 */
void iterate(int num, shared_ptr<thread> prev)
{
  const int KAPREKAR = 6174;
  const int MAX_S = 4;

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

  // Wait for previous thread to print in correct order
  if (prev != nullptr)
    prev->join();

  // Print iteration number or 8 to indicate Repdigits (1111,2222, etc.)
  cout << (num ? iteration : 8) << endl;
}

/**
 * Main function
 */
int main()
{

  int n_numbers;
  cin >> n_numbers;

  shared_ptr<thread> prev = nullptr;
  for (int i = 0; i < n_numbers; ++i)
  {
    int num;
    cin >> num;
    prev = make_shared<thread>(iterate, num, prev);
  }

  // Wait for last thread finish
  prev->join();

  return 0;
}

