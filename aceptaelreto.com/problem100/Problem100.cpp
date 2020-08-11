//============================================================================
// Author       : Rafael J. Vicente
// E-mail       : rafaelj.vicente@gmail.com
// Version      : 1.2
// Copyright    : All rights reserved
//============================================================================

#include <iostream>
#include <algorithm>
#include <list>

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
    const int KAPREKAR = 6174;
    const int MAX_S = 4;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_numbers;
    //cin >> n_numbers;
    read_int(n_numbers);

    const int CACHE_MAX_S = 10000;
    const int CACHE_DEF_VAL = -1;
    int iter_cache_arr[CACHE_MAX_S];
    fill(iter_cache_arr, iter_cache_arr + CACHE_MAX_S, CACHE_DEF_VAL);

    // Init defaults
    iter_cache_arr[KAPREKAR] = 0;
    for (int i = 0;i < CACHE_MAX_S; i+=1111)
        iter_cache_arr[i] = 8;

    int arr[MAX_S];
    for (int i = 0; i < n_numbers; ++i)
    {
        int num;
        //cin >> num;
        read_int(num);

        if (iter_cache_arr[num] != CACHE_DEF_VAL)
        {
            cout << iter_cache_arr[num] << "\n";
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
                if (iter_cache_arr[num] != CACHE_DEF_VAL)
                {
                    iteration += iter_cache_arr[num];
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
                iter_cache_arr[cached_num] = aux_iteration--;
            }

            cout << iteration << '\n';
        }
    }

    return 0;
}
 