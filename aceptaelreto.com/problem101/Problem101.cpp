//============================================================================
// Author       : Rafael J. Vicente
// E-mail       : rafaelj.vicente@gmail.com
// Version      : 1.5
// Copyright    : All rights reserved
//============================================================================

#include <iostream>

using namespace std;

void read_int(int &number)
{
    register int c = ' ';
    number = 0;
    c = getchar();
    if (c == '\n')
        c = getchar();

    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
}

void prepare_index_map(const int &n, int index_map[16])
{
    register int idx_ul = 0;
    register int idx_ur = n - 1;
    register int idx_dl = n * idx_ur;
    register int idx_dr = idx_dl + idx_ur;

    register int idx_um = n >> 1;  // n / 2
    register int idx_lm = n * idx_um;
    register int idx_rm = idx_lm + idx_ur;
    register int idx_dm = idx_dl + idx_um;

    register int idx_mm = idx_lm + idx_um;

    int im_i;
    if (n % 2 != 0)  // 3. n is odd
    {
        index_map[0] = idx_ul;  // Up
        index_map[1] = idx_um;
        index_map[2] = idx_ur;
        index_map[3] = idx_lm;  // Mid
        index_map[4] = idx_mm;
        index_map[5] = idx_rm;
        index_map[6] = idx_dl;  // Down
        index_map[7] = idx_dm;
        index_map[8] = idx_dr;
    }
    else
    {
        register int idx_um2 = idx_um - 1;
        register int idx_lm2 = n * idx_um2;
        register int idx_rm2 = idx_lm2 + idx_ur;
        register int idx_dm2 = idx_dm - 1;

        register int idx_mm2 = idx_mm - 1;
        register int idx_mm3 = idx_lm2 + idx_um;
        register int idx_mm4 = idx_mm3 - 1;

        index_map[0] = idx_ul;  // Up
        index_map[1] = idx_um2;
        index_map[2] = idx_um;
        index_map[3] = idx_ur;
        index_map[4] = idx_lm2;  // Mid A
        index_map[5] = idx_mm4;
        index_map[6] = idx_mm3;
        index_map[7] = idx_rm2;
        index_map[8] = idx_lm;  // Mid B
        index_map[9] = idx_mm2;
        index_map[10] = idx_mm;
        index_map[11] = idx_rm;
        index_map[12] = idx_dl;  // Down
        index_map[13] = idx_dm2;
        index_map[14] = idx_dm;
        index_map[15] = idx_dr;
    }
}

void evaluate_index_map(const int &n, const int* index_map, const int& CM, bool& isEsoteric)
{
    int CM2 = CM << 2;
    CM2 /= n;
    int corners = 0;
    int centers = 0;
    int sides = 0;
    if (n % 2 != 0)  // 3. n is odd
    {
        corners += index_map[0];  // Up
        sides += index_map[1];
        corners += index_map[2];
        sides += index_map[3];  // Mid
        centers += index_map[4];
        sides += index_map[5];
        corners += index_map[6];  // Down
        sides += index_map[7];
        corners += index_map[8];

        centers = centers << 2;
    }
    else
    {
        corners += index_map[0];  // Up
        sides += index_map[1];
        sides += index_map[2];
        corners += index_map[3];
        sides += index_map[4];  // Mid A
        centers += index_map[5];
        centers += index_map[6];
        sides += index_map[7];
        sides += index_map[8];  // Mid B
        centers += index_map[9];
        centers += index_map[10];
        sides += index_map[11];
        corners += index_map[12];  // Down
        sides += index_map[13];
        sides += index_map[14];
        corners += index_map[15];

        sides = sides >> 1;
    }
    isEsoteric = corners == CM2 && sides == CM2 && centers == CM2;
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

    int col_CM[1024];
    int index_map[16];

    for (int n; read_int(n), n != 0;)
    {
        int MAT_SIZE_n = n * n;

        // index_map used to take the pos (corners, sides and centers) and cache its values in one read
        prepare_index_map(n, index_map);
        int im_idx = 0;

        // gauss_sum = (n^2) * (n^2 + 1) / 2
        int gauss_sum = MAT_SIZE_n * (MAT_SIZE_n + 1);
        gauss_sum = gauss_sum >> 1;
        int gauss_sum_aux = 0;

        int CM = 0;
        std::fill(col_CM, col_CM + n, 0);

        int v_index = 0;
        int dia_CM = 0;
        int inv_dia_CM = 0;

        // Read the rest
        bool isDiabolic = true;
        for (int j = 0; isDiabolic && (j < n); ++j)
        {
            int row_CM = 0;
            for (int i = 0; i < n; ++i, ++v_index)
            {
                int value;
                read_int(value);
                gauss_sum_aux += value;
                row_CM += value;
                col_CM[i] += value;
                if (i == j)
                    dia_CM += value;
                if (i == n - 1 - j)
                    inv_dia_CM += value;
                if (index_map[im_idx] == v_index)
                    index_map[im_idx++] = value;
            }
            if (j == 0)
                CM = row_CM;
            else
                isDiabolic = row_CM == CM;
        }
        isDiabolic &= CM == dia_CM && dia_CM == inv_dia_CM;
        for (; v_index < MAT_SIZE_n; ++v_index)
        {
            int _;
            read_int(_);  // Drop unread elements
        }
        for (int i = 0; isDiabolic && i < n; ++i)
            isDiabolic = col_CM[i] == CM;
        if (!isDiabolic)
            cout << NO;
        else
        {
            // CHECK DIABOLIC EXOTERIC
            // 1. Values from 1 to n^2 (natural numbers)
            bool isEsoteric = gauss_sum == gauss_sum_aux;
            // 2 & 3 & 4. Centers
            if (isEsoteric)
                evaluate_index_map(n, index_map, CM, isEsoteric);
            cout << (isEsoteric ? ESOTERIC : DIABOLIC);
        }
    }

    return 0;
}
