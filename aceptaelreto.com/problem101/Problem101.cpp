//============================================================================
// Author       : Rafael J. Vicente
// E-mail       : rafaelj.vicente@gmail.com
// Version      : 1.3
// Copyright    : All rights reserved
//============================================================================

#include <iostream>

using namespace std;

void read_int(int &number)
{
    register int c = ' ';
    number = 0;
    for (; c = getchar(), c == ' ' || c == '\n';);
        
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

    const char* NO = "NO\n";
    const char* ESOTERIC = "ESOTERICO\n";
    const char* DIABOLIC = "DIABOLICO\n";

    const int MAX_n = 1024;
    const int MAX_MAT_SIZE_n = MAX_n * MAX_n;
    int* input_vector = new int[MAX_MAT_SIZE_n];
    bool* natural_vector = new bool[MAX_MAT_SIZE_n];
    int* col_CM = new int[MAX_n];  // Zero's
    //std::fill(input_vector, input_vector + MAX_MAT_SIZE_n, 0);
    //std::fill(natural_vector, natural_vector + MAX_MAT_SIZE_n, false);
    //std::fill(col_CM, col_CM + MAX_n, 0);

    int n;
    for(; read_int(n), n != 0;)
    {
        const int MAT_SIZE_n = n * n;
        //std::fill(input_vector, input_vector + MAT_SIZE_n, 0);
        std::fill(natural_vector, natural_vector + MAT_SIZE_n, false);

        int CM = 0;
        std::fill(col_CM, col_CM + n, 0);
        int v_index = 0;

        // CHECK DIABOLIC
        // Read first line
        for (; v_index < n; ++v_index)
        {
            int value;
            read_int(value);
            input_vector[v_index] = value;
            natural_vector[value - 1] = true;
            CM += value;
            col_CM[v_index] += value;
        }

        int dia_CM = input_vector[0];
        int inv_dia_CM = input_vector[n - 1];

        // Read the rest
        bool isDiabolic = true;
        for (int j = 1; isDiabolic && (j < n); ++j)
        {
            int row_CM = 0;
            for (int i = 0; i < n; ++i, ++v_index)
            {
                int value;
                read_int(value);
                input_vector[v_index] = value;
                natural_vector[value - 1] = true;
                row_CM += value;
                col_CM[i] += value;
                if (i == j)
                    dia_CM += value;
                if (i == n - 1 - j)
                    inv_dia_CM += value;
            }
            isDiabolic = row_CM == CM;
        }
        for (;v_index < MAT_SIZE_n; ++v_index)
        {
            int _;
            read_int(_);  // Drop unread elements
        }

        if (!isDiabolic || CM != dia_CM || dia_CM != inv_dia_CM)
        {
            cout << NO;
            continue;
        }
        for (int i = 0; isDiabolic && i < n; ++i)
            isDiabolic = col_CM[i] == CM;
        if (!isDiabolic)
        {
            cout << NO;
            continue;
        }

        // CHECK DIABOLIC EXOTERIC
        bool isEsoteric = true;

        // 1. Values from 1 to n^2 (natural numbers)
        for (int i = 0; isEsoteric && i < MAT_SIZE_n; ++i)
            isEsoteric = natural_vector[i];
        if (!isEsoteric)
        {
            cout << DIABOLIC;
            continue;
        }

        // 2. Sum of corner values == CM 
        const int CM2 = 4 * CM / n;

        const int idx_ul = 0;
        const int idx_ur = n - 1;
        const int idx_dl = n * idx_ur;
        const int idx_dr = idx_dl + idx_ur;

        isEsoteric = CM2 == (input_vector[idx_ul] + input_vector[idx_ur] + input_vector[idx_dl] + input_vector[idx_dr]);
        if (!isEsoteric)
        {
            cout << DIABOLIC;
            continue;
        }
        
        // 3 & 4. Centers
        const int idx_mu = n >> 1;  // n / 2
        const int idx_ml = n * idx_mu;
        const int idx_mr = idx_ml + idx_ur;
        const int idx_md = idx_dl + idx_mu;

        const int idx_center = idx_ml + idx_mu;

        int border_sum = input_vector[idx_mu] + input_vector[idx_ml] + input_vector[idx_mr] + input_vector[idx_md];
        int center_sum = input_vector[idx_center];

        if (n % 2 != 0)  // 3. n is odd
        {
            center_sum = center_sum << 2;  // 4 * center_sum
            isEsoteric = border_sum == CM2 && center_sum == CM2;
        }
        else
        {
            // 4. n is even
            const int idx_mu2 = idx_mu - 1;
            const int idx_ml2 = n * idx_mu2;
            const int idx_mr2 = idx_ml2 + idx_ur;
            const int idx_md2 = idx_md - 1;

            const int idx_center2 = idx_center - 1;
            const int idx_center3 = idx_ml2 + idx_mu;
            const int idx_center4 = idx_ml2 + idx_mu2;

            center_sum += input_vector[idx_center2] + input_vector[idx_center3] + input_vector[idx_center4];
            border_sum += input_vector[idx_mu2] + input_vector[idx_ml2] + input_vector[idx_mr2] + input_vector[idx_md2];
            border_sum = border_sum >> 1;  // n / 2
            isEsoteric = border_sum == CM2 && center_sum == CM2;
        }

        if (!isEsoteric)
        {
            cout << DIABOLIC;
            continue;
        }
        
        cout << ESOTERIC;
    }

    delete[] input_vector;
    delete[] natural_vector;
    delete[] col_CM;

    return 0;
}
