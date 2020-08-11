//============================================================================
// Author       : Rafael J. Vicente
// E-mail       : rafaelj.vicente@gmail.com
// Version      : 1.2
// Copyright    : All rights reserved
//============================================================================

#include <iostream>
#include <algorithm>
#include <map>
#include <list>

using namespace std;


/**
 * Main function
 */
int main()
{
    const int MAX_S = 4;

    int n_numbers;
    cin >> n_numbers;

    map<int, int> cache_map;

    int arr[MAX_S];
    for (int i = 0; i < n_numbers; ++i)
    {

        int num;
        cin >> num;

        if (num % 1111 == 0)
        {
            cout << 8 << endl;
            continue;
        }
        else
        {
            int iteration = 0;
            list<int> num_list;
            while (num != 6174)
            {
                // Load, sort and form number in array and sort
                for (int j = MAX_S - 1; j >= 0; --j)
                {
                    auto tmp = div(num, 10);
                    arr[j] = tmp.rem;
                    num = tmp.quot;
                }
                sort(arr, arr + MAX_S);
                num = arr[3] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[0] * 1;

                // Search for cached
                auto it = cache_map.find(num);
                if (it != cache_map.end())
                {
                    iteration += it->second;
                    break;
                }

                num_list.push_back(num);

                // Inverse - ordered (ex.: 4321-1234)
                num = 999 * arr[3] + 90 * arr[2] - 90 * arr[1] - 999 * arr[0];

                // Iteration++
                ++iteration;
            }

            int aux_iteration = iteration;
            for (const auto& cached_num : num_list)
            {
                cache_map[cached_num] = aux_iteration--;
            }

            cout << iteration << endl;
        }
    }

    return 0;
}

