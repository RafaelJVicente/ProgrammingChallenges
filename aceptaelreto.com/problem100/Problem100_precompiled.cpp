//============================================================================
// Author       : Rafael J. Vicente
// E-mail       : rafaelj.vicente@gmail.com
// Version      : 1.3
// Copyright    : All rights reserved
//============================================================================

#include <iostream>

const int iter_cache_arr[10000] = { 8, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 3, 6, 5, 2, 7, 1, 5, 6, 3, 6, 3, 5, 6, 3, 5, 3, 6, 5, 3, 4, 7, 2, 3, 4, 5, 4, 3, 2, 7, 6, 7, 7, 5, 5, 5, 5, 5, 7, 7, 6, 7, 1, 3, 4, 5, 4, 3, 2, 7, 4, 3, 5, 6, 3, 5, 3, 6, 5, 3, 6, 3, 6, 5, 2, 7, 2, 5, 6, 3, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 5, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 3, 4, 3, 3, 7, 7, 7, 3, 3, 4, 3, 6, 3, 5, 2, 7, 1, 5, 6, 3, 7, 4, 7, 2, 3, 5, 3, 6, 5, 3, 7, 6, 7, 7, 5, 5, 4, 3, 2, 7, 7, 6, 7, 1, 3, 4, 5, 5, 7, 7, 3, 4, 3, 5, 6, 3, 5, 3, 2, 7, 3, 6, 3, 6, 5, 2, 7, 2, 5, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 3, 6, 5, 2, 7, 1, 5, 6, 3, 3, 4, 3, 3, 7, 7, 7, 3, 3, 4, 6, 3, 4, 6, 4, 6, 6, 4, 6, 4, 5, 3, 6, 3, 7, 7, 7, 3, 3, 4, 2, 7, 4, 7, 2, 7, 1, 5, 6, 3, 7, 7, 6, 7, 7, 5, 3, 6, 5, 3, 1, 7, 6, 7, 1, 3, 4, 3, 2, 7, 5, 3, 4, 3, 5, 6, 3, 5, 7, 7, 6, 3, 6, 3, 6, 5, 2, 7, 2, 7, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 6, 3, 5, 6, 3, 5, 3, 6, 5, 3, 3, 6, 3, 5, 2, 7, 1, 5, 6, 3, 5, 3, 6, 3, 7, 7, 7, 3, 3, 4, 6, 5, 3, 6, 4, 6, 6, 4, 6, 4, 3, 2, 7, 4, 7, 7, 7, 3, 3, 4, 5, 7, 7, 6, 7, 7, 1, 5, 6, 3, 3, 1, 7, 6, 7, 1, 3, 6, 5, 3, 6, 5, 3, 4, 3, 5, 6, 3, 2, 7, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 4, 7, 2, 3, 4, 5, 4, 3, 2, 7, 7, 4, 7, 2, 3, 5, 3, 6, 5, 3, 2, 7, 4, 7, 2, 7, 1, 5, 6, 3, 3, 2, 7, 4, 7, 7, 7, 3, 3, 4, 4, 3, 2, 7, 4, 6, 6, 4, 6, 4, 5, 5, 7, 7, 6, 7, 7, 3, 3, 4, 4, 3, 1, 7, 6, 7, 1, 5, 6, 3, 3, 6, 5, 3, 4, 3, 5, 6, 5, 3, 2, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 6, 7, 7, 5, 5, 5, 5, 5, 7, 7, 7, 6, 7, 7, 5, 5, 4, 3, 2, 7, 7, 7, 6, 7, 7, 5, 3, 6, 5, 3, 5, 7, 7, 6, 7, 7, 1, 5, 6, 3, 5, 5, 7, 7, 6, 7, 7, 3, 3, 4, 5, 5, 5, 7, 7, 6, 6, 4, 6, 4, 5, 4, 3, 1, 7, 6, 7, 3, 3, 4, 5, 3, 6, 5, 3, 4, 3, 5, 6, 3, 7, 2, 5, 6, 3, 6, 3, 6, 5, 3, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 6, 7, 1, 3, 4, 5, 4, 3, 2, 7, 7, 6, 7, 1, 3, 4, 5, 5, 7, 7, 1, 7, 6, 7, 1, 3, 4, 3, 2, 7, 3, 1, 7, 6, 7, 1, 3, 6, 5, 3, 4, 3, 1, 7, 6, 7, 1, 5, 6, 3, 5, 4, 3, 1, 7, 6, 7, 3, 3, 4, 4, 5, 4, 3, 1, 7, 6, 4, 6, 4, 3, 5, 3, 6, 5, 3, 4, 3, 3, 4, 2, 7, 2, 5, 6, 3, 6, 3, 6, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 4, 3, 5, 6, 3, 5, 3, 6, 5, 3, 3, 4, 3, 5, 6, 3, 5, 3, 2, 7, 5, 3, 4, 3, 5, 6, 3, 5, 7, 7, 6, 5, 3, 4, 3, 5, 6, 3, 2, 7, 3, 6, 5, 3, 4, 3, 5, 6, 5, 3, 5, 3, 6, 5, 3, 4, 3, 5, 6, 3, 3, 5, 3, 6, 5, 3, 4, 3, 3, 4, 6, 3, 5, 3, 6, 5, 3, 4, 6, 4, 5, 2, 7, 2, 5, 6, 3, 6, 3, 4, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 6, 3, 6, 5, 2, 7, 2, 5, 6, 3, 3, 6, 3, 6, 5, 2, 7, 2, 5, 3, 6, 3, 6, 3, 6, 5, 2, 7, 2, 7, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 3, 2, 7, 2, 5, 6, 3, 6, 3, 6, 3, 5, 2, 7, 2, 5, 6, 3, 6, 3, 4, 6, 5, 2, 7, 2, 5, 6, 3, 6, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 5, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 3, 4, 3, 3, 7, 7, 7, 3, 3, 4, 3, 6, 3, 5, 2, 7, 1, 5, 6, 3, 7, 4, 7, 2, 3, 5, 3, 6, 5, 3, 7, 6, 7, 7, 5, 5, 4, 3, 2, 7, 7, 6, 7, 1, 3, 4, 5, 5, 7, 7, 3, 4, 3, 5, 6, 3, 5, 3, 2, 7, 3, 6, 3, 6, 5, 2, 7, 2, 5, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 8, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 3, 3, 6, 4, 3, 6, 5, 2, 7, 1, 5, 6, 4, 6, 3, 5, 6, 3, 5, 3, 6, 5, 6, 4, 7, 2, 3, 4, 5, 4, 3, 2, 6, 6, 7, 7, 5, 5, 5, 5, 5, 7, 4, 6, 7, 1, 3, 4, 5, 4, 3, 2, 6, 4, 3, 5, 6, 3, 5, 3, 6, 5, 4, 6, 3, 6, 5, 2, 7, 2, 5, 6, 3, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 5, 4, 3, 3, 7, 7, 7, 3, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 3, 3, 4, 3, 3, 7, 7, 7, 3, 3, 7, 3, 6, 3, 5, 2, 7, 1, 5, 6, 7, 7, 4, 7, 2, 3, 5, 3, 6, 5, 7, 7, 6, 7, 7, 5, 5, 4, 3, 2, 3, 7, 6, 7, 1, 3, 4, 5, 5, 7, 3, 3, 4, 3, 5, 6, 3, 5, 3, 2, 4, 3, 6, 3, 6, 5, 2, 7, 2, 5, 3, 6, 3, 5, 2, 7, 1, 5, 6, 3, 6, 4, 3, 6, 5, 2, 7, 1, 5, 6, 3, 3, 4, 3, 3, 7, 7, 7, 3, 3, 5, 6, 3, 4, 6, 4, 6, 6, 4, 6, 2, 5, 3, 6, 3, 7, 7, 7, 3, 3, 7, 2, 7, 4, 7, 2, 7, 1, 5, 6, 1, 7, 7, 6, 7, 7, 5, 3, 6, 5, 5, 1, 7, 6, 7, 1, 3, 4, 3, 2, 6, 5, 3, 4, 3, 5, 6, 3, 5, 7, 3, 6, 3, 6, 3, 6, 5, 2, 7, 2, 7, 4, 7, 2, 3, 5, 3, 6, 5, 3, 4, 6, 3, 5, 6, 3, 5, 3, 6, 5, 7, 3, 6, 3, 5, 2, 7, 1, 5, 6, 2, 5, 3, 6, 3, 7, 7, 7, 3, 3, 3, 6, 5, 3, 6, 4, 6, 6, 4, 6, 5, 3, 2, 7, 4, 7, 7, 7, 3, 3, 3, 5, 7, 7, 6, 7, 7, 1, 5, 6, 6, 3, 1, 7, 6, 7, 1, 3, 6, 5, 5, 6, 5, 3, 4, 3, 5, 6, 3, 2, 3, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 6, 7, 7, 5, 5, 4, 3, 2, 7, 6, 4, 7, 2, 3, 4, 5, 4, 3, 2, 7, 7, 4, 7, 2, 3, 5, 3, 6, 5, 7, 2, 7, 4, 7, 2, 7, 1, 5, 6, 5, 3, 2, 7, 4, 7, 7, 7, 3, 3, 5, 4, 3, 2, 7, 4, 6, 6, 4, 6, 4, 5, 5, 7, 7, 6, 7, 7, 3, 3, 3, 4, 3, 1, 7, 6, 7, 1, 5, 6, 2, 3, 6, 5, 3, 4, 3, 5, 6, 5, 7, 2, 5, 6, 3, 6, 3, 6, 5, 2, 7, 6, 7, 1, 3, 4, 5, 5, 7, 7, 6, 6, 7, 7, 5, 5, 5, 5, 5, 7, 7, 7, 6, 7, 7, 5, 5, 4, 3, 2, 1, 7, 7, 6, 7, 7, 5, 3, 6, 5, 3, 5, 7, 7, 6, 7, 7, 1, 5, 6, 4, 5, 5, 7, 7, 6, 7, 7, 3, 3, 5, 5, 5, 5, 7, 7, 6, 6, 4, 6, 5, 5, 4, 3, 1, 7, 6, 7, 3, 3, 7, 5, 3, 6, 5, 3, 4, 3, 5, 6, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 3, 4, 3, 5, 6, 3, 5, 3, 2, 7, 4, 6, 7, 1, 3, 4, 5, 4, 3, 2, 3, 7, 6, 7, 1, 3, 4, 5, 5, 7, 5, 1, 7, 6, 7, 1, 3, 4, 3, 2, 6, 3, 1, 7, 6, 7, 1, 3, 6, 5, 3, 4, 3, 1, 7, 6, 7, 1, 5, 6, 5, 5, 4, 3, 1, 7, 6, 7, 3, 3, 3, 4, 5, 4, 3, 1, 7, 6, 4, 6, 2, 3, 5, 3, 6, 5, 3, 4, 3, 3, 7, 2, 7, 2, 5, 6, 3, 6, 3, 6, 3, 6, 3, 6, 5, 2, 7, 2, 5, 3, 6, 4, 3, 5, 6, 3, 5, 3, 6, 5, 3, 3, 4, 3, 5, 6, 3, 5, 3, 2, 6, 5, 3, 4, 3, 5, 6, 3, 5, 7, 5, 6, 5, 3, 4, 3, 5, 6, 3, 2, 2, 3, 6, 5, 3, 4, 3, 5, 6, 5, 7, 5, 3, 6, 5, 3, 4, 3, 5, 6, 2, 3, 5, 3, 6, 5, 3, 4, 3, 3, 5, 6, 3, 5, 3, 6, 5, 3, 4, 6, 3, 5, 2, 7, 2, 5, 6, 3, 6, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 6, 3, 6, 5, 2, 7, 2, 5, 6, 4, 3, 6, 3, 6, 5, 2, 7, 2, 5, 3, 6, 3, 6, 3, 6, 5, 2, 7, 2, 3, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 7, 2, 7, 2, 5, 6, 3, 6, 3, 6, 3, 5, 2, 7, 2, 5, 6, 3, 6, 3, 3, 6, 5, 2, 7, 2, 5, 6, 3, 6, 4, 3, 6, 5, 2, 7, 1, 5, 6, 3, 3, 4, 3, 3, 7, 7, 7, 3, 3, 4, 6, 3, 4, 6, 4, 6, 6, 4, 6, 4, 5, 3, 6, 3, 7, 7, 7, 3, 3, 4, 2, 7, 4, 7, 2, 7, 1, 5, 6, 3, 7, 7, 6, 7, 7, 5, 3, 6, 5, 3, 1, 7, 6, 7, 1, 3, 4, 3, 2, 7, 5, 3, 4, 3, 5, 6, 3, 5, 7, 7, 6, 3, 6, 3, 6, 5, 2, 7, 2, 7, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 5, 4, 3, 3, 7, 7, 7, 3, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 3, 3, 4, 3, 3, 7, 7, 7, 3, 3, 7, 3, 6, 3, 5, 2, 7, 1, 5, 6, 7, 7, 4, 7, 2, 3, 5, 3, 6, 5, 7, 7, 6, 7, 7, 5, 5, 4, 3, 2, 3, 7, 6, 7, 1, 3, 4, 5, 5, 7, 3, 3, 4, 3, 5, 6, 3, 5, 3, 2, 4, 3, 6, 3, 6, 5, 2, 7, 2, 5, 6, 3, 4, 6, 4, 6, 6, 4, 6, 4, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 8, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 3, 4, 6, 4, 3, 6, 5, 2, 7, 1, 5, 6, 4, 6, 3, 5, 6, 3, 5, 3, 6, 6, 6, 4, 7, 2, 3, 4, 5, 4, 3, 4, 6, 6, 7, 7, 5, 5, 5, 5, 5, 6, 4, 6, 7, 1, 3, 4, 5, 4, 3, 4, 6, 4, 3, 5, 6, 3, 5, 3, 6, 5, 3, 6, 3, 7, 7, 7, 3, 3, 4, 3, 3, 4, 3, 3, 7, 7, 7, 3, 3, 6, 4, 5, 4, 3, 3, 7, 7, 7, 3, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 7, 3, 3, 4, 3, 3, 7, 7, 7, 3, 7, 7, 3, 6, 3, 5, 2, 7, 1, 5, 7, 7, 7, 4, 7, 2, 3, 5, 3, 6, 3, 7, 7, 6, 7, 7, 5, 5, 4, 3, 3, 3, 7, 6, 7, 1, 3, 4, 5, 5, 4, 3, 3, 4, 3, 5, 6, 3, 5, 3, 2, 7, 4, 7, 2, 7, 1, 5, 6, 3, 7, 3, 6, 3, 5, 2, 7, 1, 5, 6, 4, 6, 4, 3, 6, 5, 2, 7, 1, 5, 7, 3, 3, 4, 3, 3, 7, 7, 7, 3, 2, 5, 6, 3, 4, 6, 4, 6, 6, 4, 7, 2, 5, 3, 6, 3, 7, 7, 7, 3, 1, 7, 2, 7, 4, 7, 2, 7, 1, 5, 5, 1, 7, 7, 6, 7, 7, 5, 3, 6, 6, 5, 1, 7, 6, 7, 1, 3, 4, 3, 3, 6, 5, 3, 4, 3, 5, 6, 3, 5, 7, 7, 6, 7, 7, 5, 3, 6, 5, 3, 7, 7, 4, 7, 2, 3, 5, 3, 6, 5, 6, 4, 6, 3, 5, 6, 3, 5, 3, 6, 7, 7, 3, 6, 3, 5, 2, 7, 1, 5, 7, 2, 5, 3, 6, 3, 7, 7, 7, 3, 5, 3, 6, 5, 3, 6, 4, 6, 6, 4, 3, 5, 3, 2, 7, 4, 7, 7, 7, 3, 6, 3, 5, 7, 7, 6, 7, 7, 1, 5, 5, 6, 3, 1, 7, 6, 7, 1, 3, 6, 3, 5, 6, 5, 3, 4, 3, 5, 6, 3, 1, 7, 6, 7, 1, 3, 4, 3, 2, 7, 7, 7, 6, 7, 7, 5, 5, 4, 3, 2, 6, 6, 4, 7, 2, 3, 4, 5, 4, 3, 7, 7, 7, 4, 7, 2, 3, 5, 3, 6, 1, 7, 2, 7, 4, 7, 2, 7, 1, 5, 3, 5, 3, 2, 7, 4, 7, 7, 7, 3, 4, 5, 4, 3, 2, 7, 4, 6, 6, 4, 3, 4, 5, 5, 7, 7, 6, 7, 7, 3, 2, 3, 4, 3, 1, 7, 6, 7, 1, 5, 7, 2, 3, 6, 5, 3, 4, 3, 5, 6, 5, 3, 4, 3, 5, 6, 3, 5, 7, 7, 3, 7, 6, 7, 1, 3, 4, 5, 5, 7, 4, 6, 6, 7, 7, 5, 5, 5, 5, 5, 3, 7, 7, 6, 7, 7, 5, 5, 4, 3, 5, 1, 7, 7, 6, 7, 7, 5, 3, 6, 6, 3, 5, 7, 7, 6, 7, 7, 1, 5, 3, 4, 5, 5, 7, 7, 6, 7, 7, 3, 5, 5, 5, 5, 5, 7, 7, 6, 6, 4, 7, 5, 5, 4, 3, 1, 7, 6, 7, 3, 7, 7, 5, 3, 6, 5, 3, 4, 3, 5, 6, 3, 6, 3, 6, 5, 2, 7, 2, 7, 3, 3, 4, 3, 5, 6, 3, 5, 3, 2, 6, 4, 6, 7, 1, 3, 4, 5, 4, 3, 3, 3, 7, 6, 7, 1, 3, 4, 5, 5, 6, 5, 1, 7, 6, 7, 1, 3, 4, 3, 5, 6, 3, 1, 7, 6, 7, 1, 3, 6, 2, 3, 4, 3, 1, 7, 6, 7, 1, 5, 7, 5, 5, 4, 3, 1, 7, 6, 7, 3, 2, 3, 4, 5, 4, 3, 1, 7, 6, 4, 7, 2, 3, 5, 3, 6, 5, 3, 4, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 4, 3, 6, 3, 6, 5, 2, 7, 2, 5, 4, 6, 4, 3, 5, 6, 3, 5, 3, 6, 4, 3, 3, 4, 3, 5, 6, 3, 5, 3, 3, 6, 5, 3, 4, 3, 5, 6, 3, 5, 3, 5, 6, 5, 3, 4, 3, 5, 6, 3, 7, 2, 3, 6, 5, 3, 4, 3, 5, 6, 7, 7, 5, 3, 6, 5, 3, 4, 3, 5, 7, 2, 3, 5, 3, 6, 5, 3, 4, 3, 3, 5, 6, 3, 5, 3, 6, 5, 3, 4, 6, 3, 5, 6, 3, 5, 3, 6, 5, 3, 3, 6, 3, 5, 2, 7, 1, 5, 6, 3, 5, 3, 6, 3, 7, 7, 7, 3, 3, 4, 6, 5, 3, 6, 4, 6, 6, 4, 6, 4, 3, 2, 7, 4, 7, 7, 7, 3, 3, 4, 5, 7, 7, 6, 7, 7, 1, 5, 6, 3, 3, 1, 7, 6, 7, 1, 3, 6, 5, 3, 6, 5, 3, 4, 3, 5, 6, 3, 2, 7, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 6, 3, 5, 2, 7, 1, 5, 6, 3, 6, 4, 3, 6, 5, 2, 7, 1, 5, 6, 3, 3, 4, 3, 3, 7, 7, 7, 3, 3, 5, 6, 3, 4, 6, 4, 6, 6, 4, 6, 2, 5, 3, 6, 3, 7, 7, 7, 3, 3, 7, 2, 7, 4, 7, 2, 7, 1, 5, 6, 1, 7, 7, 6, 7, 7, 5, 3, 6, 5, 5, 1, 7, 6, 7, 1, 3, 4, 3, 2, 6, 5, 3, 4, 3, 5, 6, 3, 5, 7, 3, 6, 3, 6, 3, 6, 5, 2, 7, 2, 5, 3, 6, 3, 7, 7, 7, 3, 3, 4, 3, 3, 4, 3, 3, 7, 7, 7, 3, 3, 6, 4, 5, 4, 3, 3, 7, 7, 7, 3, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 7, 3, 3, 4, 3, 3, 7, 7, 7, 3, 7, 7, 3, 6, 3, 5, 2, 7, 1, 5, 7, 7, 7, 4, 7, 2, 3, 5, 3, 6, 3, 7, 7, 6, 7, 7, 5, 5, 4, 3, 3, 3, 7, 6, 7, 1, 3, 4, 5, 5, 4, 3, 3, 4, 3, 5, 6, 3, 5, 3, 6, 5, 3, 6, 4, 6, 6, 4, 6, 4, 5, 6, 3, 4, 6, 4, 6, 6, 4, 6, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 8, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 6, 4, 6, 4, 3, 6, 5, 2, 7, 1, 6, 6, 4, 6, 3, 5, 6, 3, 5, 3, 4, 6, 6, 4, 7, 2, 3, 4, 5, 4, 6, 4, 6, 6, 7, 7, 5, 5, 5, 5, 4, 6, 4, 6, 7, 1, 3, 4, 5, 4, 3, 2, 7, 4, 7, 7, 7, 3, 3, 4, 2, 5, 3, 6, 3, 7, 7, 7, 3, 3, 7, 3, 3, 4, 3, 3, 7, 7, 7, 3, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 6, 6, 7, 7, 3, 3, 4, 3, 3, 7, 7, 7, 7, 7, 7, 3, 6, 3, 5, 2, 7, 1, 3, 7, 7, 7, 4, 7, 2, 3, 5, 3, 3, 3, 7, 7, 6, 7, 7, 5, 5, 4, 4, 3, 3, 7, 6, 7, 1, 3, 4, 5, 5, 7, 7, 6, 7, 7, 1, 5, 6, 3, 7, 2, 7, 4, 7, 2, 7, 1, 5, 6, 7, 7, 3, 6, 3, 5, 2, 7, 1, 5, 6, 4, 6, 4, 3, 6, 5, 2, 7, 1, 7, 7, 3, 3, 4, 3, 3, 7, 7, 7, 7, 2, 5, 6, 3, 4, 6, 4, 6, 6, 1, 7, 2, 5, 3, 6, 3, 7, 7, 7, 5, 1, 7, 2, 7, 4, 7, 2, 7, 1, 6, 5, 1, 7, 7, 6, 7, 7, 5, 3, 3, 6, 5, 1, 7, 6, 7, 1, 3, 4, 3, 1, 7, 6, 7, 1, 3, 6, 5, 3, 1, 7, 7, 6, 7, 7, 5, 3, 6, 5, 7, 7, 7, 4, 7, 2, 3, 5, 3, 6, 6, 6, 4, 6, 3, 5, 6, 3, 5, 3, 7, 7, 7, 3, 6, 3, 5, 2, 7, 1, 1, 7, 2, 5, 3, 6, 3, 7, 7, 7, 3, 5, 3, 6, 5, 3, 6, 4, 6, 6, 6, 3, 5, 3, 2, 7, 4, 7, 7, 7, 5, 6, 3, 5, 7, 7, 6, 7, 7, 1, 3, 5, 6, 3, 1, 7, 6, 7, 1, 3, 6, 5, 3, 4, 3, 5, 6, 3, 2, 7, 5, 1, 7, 6, 7, 1, 3, 4, 3, 2, 3, 7, 7, 6, 7, 7, 5, 5, 4, 3, 4, 6, 6, 4, 7, 2, 3, 4, 5, 4, 3, 7, 7, 7, 4, 7, 2, 3, 5, 3, 5, 1, 7, 2, 7, 4, 7, 2, 7, 1, 6, 3, 5, 3, 2, 7, 4, 7, 7, 7, 3, 4, 5, 4, 3, 2, 7, 4, 6, 6, 2, 3, 4, 5, 5, 7, 7, 6, 7, 7, 7, 2, 3, 4, 3, 1, 7, 6, 7, 1, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 6, 5, 3, 4, 3, 5, 6, 3, 5, 7, 3, 3, 7, 6, 7, 1, 3, 4, 5, 5, 6, 4, 6, 6, 7, 7, 5, 5, 5, 5, 3, 3, 7, 7, 6, 7, 7, 5, 5, 4, 6, 5, 1, 7, 7, 6, 7, 7, 5, 3, 5, 6, 3, 5, 7, 7, 6, 7, 7, 1, 2, 3, 4, 5, 5, 7, 7, 6, 7, 7, 7, 5, 5, 5, 5, 5, 7, 7, 6, 6, 7, 7, 5, 5, 4, 3, 1, 7, 6, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 6, 3, 6, 3, 6, 5, 2, 7, 2, 4, 3, 3, 4, 3, 5, 6, 3, 5, 3, 4, 6, 4, 6, 7, 1, 3, 4, 5, 4, 4, 3, 3, 7, 6, 7, 1, 3, 4, 5, 3, 6, 5, 1, 7, 6, 7, 1, 3, 4, 3, 5, 6, 3, 1, 7, 6, 7, 1, 3, 7, 2, 3, 4, 3, 1, 7, 6, 7, 1, 7, 7, 5, 5, 4, 3, 1, 7, 6, 7, 7, 2, 3, 4, 5, 4, 3, 1, 7, 6, 4, 7, 2, 3, 4, 5, 4, 3, 2, 7, 7, 4, 7, 2, 3, 5, 3, 6, 5, 3, 2, 7, 4, 7, 2, 7, 1, 5, 6, 3, 3, 2, 7, 4, 7, 7, 7, 3, 3, 4, 4, 3, 2, 7, 4, 6, 6, 4, 6, 4, 5, 5, 7, 7, 6, 7, 7, 3, 3, 4, 4, 3, 1, 7, 6, 7, 1, 5, 6, 3, 3, 6, 5, 3, 4, 3, 5, 6, 5, 3, 2, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 4, 7, 2, 3, 5, 3, 6, 5, 3, 4, 6, 3, 5, 6, 3, 5, 3, 6, 5, 7, 3, 6, 3, 5, 2, 7, 1, 5, 6, 2, 5, 3, 6, 3, 7, 7, 7, 3, 3, 3, 6, 5, 3, 6, 4, 6, 6, 4, 6, 5, 3, 2, 7, 4, 7, 7, 7, 3, 3, 3, 5, 7, 7, 6, 7, 7, 1, 5, 6, 6, 3, 1, 7, 6, 7, 1, 3, 6, 5, 5, 6, 5, 3, 4, 3, 5, 6, 3, 2, 3, 5, 6, 3, 6, 3, 6, 5, 2, 7, 2, 7, 4, 7, 2, 7, 1, 5, 6, 3, 7, 3, 6, 3, 5, 2, 7, 1, 5, 6, 4, 6, 4, 3, 6, 5, 2, 7, 1, 5, 7, 3, 3, 4, 3, 3, 7, 7, 7, 3, 2, 5, 6, 3, 4, 6, 4, 6, 6, 4, 7, 2, 5, 3, 6, 3, 7, 7, 7, 3, 1, 7, 2, 7, 4, 7, 2, 7, 1, 5, 5, 1, 7, 7, 6, 7, 7, 5, 3, 6, 6, 5, 1, 7, 6, 7, 1, 3, 4, 3, 3, 6, 5, 3, 4, 3, 5, 6, 3, 5, 3, 2, 7, 4, 7, 7, 7, 3, 3, 4, 2, 5, 3, 6, 3, 7, 7, 7, 3, 3, 7, 3, 3, 4, 3, 3, 7, 7, 7, 3, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 6, 6, 7, 7, 3, 3, 4, 3, 3, 7, 7, 7, 7, 7, 7, 3, 6, 3, 5, 2, 7, 1, 3, 7, 7, 7, 4, 7, 2, 3, 5, 3, 3, 3, 7, 7, 6, 7, 7, 5, 5, 4, 4, 3, 3, 7, 6, 7, 1, 3, 4, 5, 4, 3, 2, 7, 4, 6, 6, 4, 6, 4, 3, 6, 5, 3, 6, 4, 6, 6, 4, 6, 2, 5, 6, 3, 4, 6, 4, 6, 6, 4, 7, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 8, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 7, 7, 6, 6, 4, 6, 4, 3, 6, 5, 2, 7, 4, 6, 6, 4, 6, 3, 5, 6, 3, 5, 6, 4, 6, 6, 4, 7, 2, 3, 4, 5, 4, 6, 4, 6, 6, 7, 7, 5, 5, 5, 5, 5, 7, 7, 6, 7, 7, 3, 3, 4, 5, 3, 2, 7, 4, 7, 7, 7, 3, 3, 7, 2, 5, 3, 6, 3, 7, 7, 7, 3, 7, 7, 3, 3, 4, 3, 3, 7, 7, 7, 6, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 6, 7, 7, 7, 3, 3, 4, 3, 3, 7, 7, 3, 7, 7, 7, 3, 6, 3, 5, 2, 7, 3, 3, 7, 7, 7, 4, 7, 2, 3, 5, 4, 3, 3, 7, 7, 6, 7, 7, 5, 5, 4, 3, 1, 7, 6, 7, 1, 5, 6, 3, 3, 5, 7, 7, 6, 7, 7, 1, 5, 6, 1, 7, 2, 7, 4, 7, 2, 7, 1, 5, 7, 7, 7, 3, 6, 3, 5, 2, 7, 1, 6, 6, 4, 6, 4, 3, 6, 5, 2, 7, 7, 7, 7, 3, 3, 4, 3, 3, 7, 7, 1, 7, 2, 5, 6, 3, 4, 6, 4, 6, 5, 1, 7, 2, 5, 3, 6, 3, 7, 7, 6, 5, 1, 7, 2, 7, 4, 7, 2, 7, 3, 6, 5, 1, 7, 7, 6, 7, 7, 5, 3, 6, 5, 3, 4, 3, 5, 6, 5, 3, 6, 3, 1, 7, 6, 7, 1, 3, 6, 5, 5, 1, 7, 7, 6, 7, 7, 5, 3, 6, 3, 7, 7, 7, 4, 7, 2, 3, 5, 3, 4, 6, 6, 4, 6, 3, 5, 6, 3, 5, 3, 7, 7, 7, 3, 6, 3, 5, 2, 7, 5, 1, 7, 2, 5, 3, 6, 3, 7, 7, 6, 3, 5, 3, 6, 5, 3, 6, 4, 6, 5, 6, 3, 5, 3, 2, 7, 4, 7, 7, 3, 5, 6, 3, 5, 7, 7, 6, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 2, 7, 5, 6, 5, 3, 4, 3, 5, 6, 3, 2, 6, 5, 1, 7, 6, 7, 1, 3, 4, 3, 3, 3, 7, 7, 6, 7, 7, 5, 5, 4, 6, 4, 6, 6, 4, 7, 2, 3, 4, 5, 3, 3, 7, 7, 7, 4, 7, 2, 3, 5, 6, 5, 1, 7, 2, 7, 4, 7, 2, 7, 5, 6, 3, 5, 3, 2, 7, 4, 7, 7, 2, 3, 4, 5, 4, 3, 2, 7, 4, 6, 7, 2, 3, 4, 5, 5, 7, 7, 6, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 3, 5, 6, 3, 6, 3, 6, 5, 2, 7, 3, 6, 5, 3, 4, 3, 5, 6, 3, 5, 4, 3, 3, 7, 6, 7, 1, 3, 4, 5, 4, 6, 4, 6, 6, 7, 7, 5, 5, 5, 4, 3, 3, 7, 7, 6, 7, 7, 5, 5, 3, 6, 5, 1, 7, 7, 6, 7, 7, 5, 3, 5, 6, 3, 5, 7, 7, 6, 7, 7, 7, 2, 3, 4, 5, 5, 7, 7, 6, 7, 7, 7, 5, 5, 5, 5, 5, 7, 7, 6, 6, 7, 7, 5, 5, 5, 5, 5, 7, 7, 7, 6, 7, 7, 5, 5, 4, 3, 2, 7, 7, 7, 6, 7, 7, 5, 3, 6, 5, 3, 5, 7, 7, 6, 7, 7, 1, 5, 6, 3, 5, 5, 7, 7, 6, 7, 7, 3, 3, 4, 5, 5, 5, 7, 7, 6, 6, 4, 6, 4, 5, 4, 3, 1, 7, 6, 7, 3, 3, 4, 5, 3, 6, 5, 3, 4, 3, 5, 6, 3, 7, 2, 5, 6, 3, 6, 3, 6, 5, 3, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 6, 7, 7, 5, 5, 4, 3, 2, 7, 6, 4, 7, 2, 3, 4, 5, 4, 3, 2, 7, 7, 4, 7, 2, 3, 5, 3, 6, 5, 7, 2, 7, 4, 7, 2, 7, 1, 5, 6, 5, 3, 2, 7, 4, 7, 7, 7, 3, 3, 5, 4, 3, 2, 7, 4, 6, 6, 4, 6, 4, 5, 5, 7, 7, 6, 7, 7, 3, 3, 3, 4, 3, 1, 7, 6, 7, 1, 5, 6, 2, 3, 6, 5, 3, 4, 3, 5, 6, 5, 7, 2, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 6, 7, 7, 5, 3, 6, 5, 3, 7, 7, 4, 7, 2, 3, 5, 3, 6, 5, 6, 4, 6, 3, 5, 6, 3, 5, 3, 6, 7, 7, 3, 6, 3, 5, 2, 7, 1, 5, 7, 2, 5, 3, 6, 3, 7, 7, 7, 3, 5, 3, 6, 5, 3, 6, 4, 6, 6, 4, 3, 5, 3, 2, 7, 4, 7, 7, 7, 3, 6, 3, 5, 7, 7, 6, 7, 7, 1, 5, 5, 6, 3, 1, 7, 6, 7, 1, 3, 6, 3, 5, 6, 5, 3, 4, 3, 5, 6, 3, 5, 7, 7, 6, 7, 7, 1, 5, 6, 3, 7, 2, 7, 4, 7, 2, 7, 1, 5, 6, 7, 7, 3, 6, 3, 5, 2, 7, 1, 5, 6, 4, 6, 4, 3, 6, 5, 2, 7, 1, 7, 7, 3, 3, 4, 3, 3, 7, 7, 7, 7, 2, 5, 6, 3, 4, 6, 4, 6, 6, 1, 7, 2, 5, 3, 6, 3, 7, 7, 7, 5, 1, 7, 2, 7, 4, 7, 2, 7, 1, 6, 5, 1, 7, 7, 6, 7, 7, 5, 3, 3, 6, 5, 1, 7, 6, 7, 1, 3, 4, 5, 5, 7, 7, 6, 7, 7, 3, 3, 4, 5, 3, 2, 7, 4, 7, 7, 7, 3, 3, 7, 2, 5, 3, 6, 3, 7, 7, 7, 3, 7, 7, 3, 3, 4, 3, 3, 7, 7, 7, 6, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 6, 7, 7, 7, 3, 3, 4, 3, 3, 7, 7, 3, 7, 7, 7, 3, 6, 3, 5, 2, 7, 3, 3, 7, 7, 7, 4, 7, 2, 3, 5, 4, 3, 3, 7, 7, 6, 7, 7, 5, 5, 5, 5, 5, 7, 7, 6, 6, 4, 6, 4, 5, 4, 3, 2, 7, 4, 6, 6, 4, 6, 5, 3, 6, 5, 3, 6, 4, 6, 6, 4, 7, 2, 5, 6, 3, 4, 6, 4, 6, 6, 7, 7, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 8, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 7, 4, 6, 6, 4, 6, 4, 3, 6, 5, 2, 6, 4, 6, 6, 4, 6, 3, 5, 6, 3, 4, 6, 4, 6, 6, 4, 7, 2, 3, 4, 5, 4, 3, 1, 7, 6, 7, 3, 3, 4, 4, 5, 5, 7, 7, 6, 7, 7, 3, 3, 3, 5, 3, 2, 7, 4, 7, 7, 7, 3, 1, 7, 2, 5, 3, 6, 3, 7, 7, 7, 7, 7, 7, 3, 3, 4, 3, 3, 7, 7, 6, 6, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 3, 7, 7, 7, 3, 3, 4, 3, 3, 7, 3, 3, 7, 7, 7, 3, 6, 3, 5, 2, 4, 3, 3, 7, 7, 7, 4, 7, 2, 3, 5, 3, 6, 5, 3, 4, 3, 5, 6, 3, 3, 4, 3, 1, 7, 6, 7, 1, 5, 6, 6, 3, 5, 7, 7, 6, 7, 7, 1, 5, 5, 1, 7, 2, 7, 4, 7, 2, 7, 1, 3, 7, 7, 7, 3, 6, 3, 5, 2, 7, 4, 6, 6, 4, 6, 4, 3, 6, 5, 2, 3, 7, 7, 7, 3, 3, 4, 3, 3, 7, 5, 1, 7, 2, 5, 6, 3, 4, 6, 4, 6, 5, 1, 7, 2, 5, 3, 6, 3, 7, 3, 6, 5, 1, 7, 2, 7, 4, 7, 2, 7, 2, 5, 6, 3, 6, 3, 6, 5, 3, 2, 3, 6, 5, 3, 4, 3, 5, 6, 5, 5, 6, 3, 1, 7, 6, 7, 1, 3, 6, 6, 5, 1, 7, 7, 6, 7, 7, 5, 3, 3, 3, 7, 7, 7, 4, 7, 2, 3, 5, 6, 4, 6, 6, 4, 6, 3, 5, 6, 3, 3, 3, 7, 7, 7, 3, 6, 3, 5, 2, 6, 5, 1, 7, 2, 5, 3, 6, 3, 7, 5, 6, 3, 5, 3, 6, 5, 3, 6, 4, 3, 5, 6, 3, 5, 3, 2, 7, 4, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 2, 3, 5, 6, 5, 3, 4, 3, 5, 6, 3, 3, 6, 5, 1, 7, 6, 7, 1, 3, 4, 4, 3, 3, 7, 7, 6, 7, 7, 5, 5, 4, 6, 4, 6, 6, 4, 7, 2, 3, 4, 4, 3, 3, 7, 7, 7, 4, 7, 2, 3, 3, 6, 5, 1, 7, 2, 7, 4, 7, 2, 3, 5, 6, 3, 5, 3, 2, 7, 4, 7, 7, 2, 3, 4, 5, 4, 3, 2, 7, 4, 6, 7, 1, 3, 4, 5, 4, 3, 2, 7, 7, 6, 7, 1, 3, 4, 5, 5, 7, 7, 1, 7, 6, 7, 1, 3, 4, 3, 2, 7, 3, 1, 7, 6, 7, 1, 3, 6, 5, 3, 4, 3, 1, 7, 6, 7, 1, 5, 6, 3, 5, 4, 3, 1, 7, 6, 7, 3, 3, 4, 4, 5, 4, 3, 1, 7, 6, 4, 6, 4, 3, 5, 3, 6, 5, 3, 4, 3, 3, 4, 2, 7, 2, 5, 6, 3, 6, 3, 6, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 6, 7, 1, 3, 4, 5, 5, 7, 7, 6, 6, 7, 7, 5, 5, 5, 5, 5, 7, 7, 7, 6, 7, 7, 5, 5, 4, 3, 2, 1, 7, 7, 6, 7, 7, 5, 3, 6, 5, 3, 5, 7, 7, 6, 7, 7, 1, 5, 6, 4, 5, 5, 7, 7, 6, 7, 7, 3, 3, 5, 5, 5, 5, 7, 7, 6, 6, 4, 6, 5, 5, 4, 3, 0, 7, 6, 7, 3, 3, 7, 5, 3, 6, 5, 3, 4, 3, 5, 6, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 1, 7, 6, 7, 1, 3, 4, 3, 2, 7, 7, 7, 6, 7, 7, 5, 5, 4, 3, 2, 6, 6, 4, 7, 2, 3, 4, 5, 4, 3, 7, 7, 7, 4, 7, 2, 3, 5, 3, 6, 1, 7, 2, 7, 4, 7, 2, 7, 1, 5, 3, 5, 3, 2, 7, 4, 7, 7, 7, 3, 4, 5, 4, 3, 2, 7, 4, 6, 6, 4, 3, 4, 5, 5, 7, 7, 6, 7, 7, 3, 2, 3, 4, 3, 1, 7, 6, 7, 1, 5, 7, 2, 3, 6, 5, 3, 4, 3, 5, 6, 3, 1, 7, 6, 7, 1, 3, 6, 5, 3, 1, 7, 7, 6, 7, 7, 5, 3, 6, 5, 7, 7, 7, 4, 7, 2, 3, 5, 3, 6, 6, 6, 4, 6, 3, 5, 6, 3, 5, 3, 7, 7, 7, 3, 6, 3, 5, 2, 7, 1, 1, 7, 2, 5, 3, 6, 3, 7, 7, 7, 3, 5, 3, 6, 5, 3, 6, 4, 6, 6, 6, 3, 5, 3, 2, 7, 4, 7, 7, 7, 5, 6, 3, 5, 7, 7, 6, 7, 7, 1, 3, 5, 6, 3, 1, 7, 6, 7, 1, 3, 4, 3, 1, 7, 6, 7, 1, 5, 6, 3, 3, 5, 7, 7, 6, 7, 7, 1, 5, 6, 1, 7, 2, 7, 4, 7, 2, 7, 1, 5, 7, 7, 7, 3, 6, 3, 5, 2, 7, 1, 6, 6, 4, 6, 4, 3, 6, 5, 2, 7, 7, 7, 7, 3, 3, 4, 3, 3, 7, 7, 1, 7, 2, 5, 6, 3, 4, 6, 4, 6, 5, 1, 7, 2, 5, 3, 6, 3, 7, 7, 6, 5, 1, 7, 2, 7, 4, 7, 2, 7, 3, 6, 5, 1, 7, 7, 6, 7, 7, 5, 5, 4, 3, 1, 7, 6, 7, 3, 3, 4, 4, 5, 5, 7, 7, 6, 7, 7, 3, 3, 3, 5, 3, 2, 7, 4, 7, 7, 7, 3, 1, 7, 2, 5, 3, 6, 3, 7, 7, 7, 7, 7, 7, 3, 3, 4, 3, 3, 7, 7, 6, 6, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 3, 7, 7, 7, 3, 3, 4, 3, 3, 7, 3, 3, 7, 7, 7, 3, 6, 3, 5, 2, 4, 3, 3, 7, 7, 7, 4, 7, 2, 3, 4, 5, 4, 3, 1, 7, 6, 4, 6, 4, 5, 5, 5, 5, 7, 7, 6, 6, 4, 6, 4, 5, 4, 3, 2, 7, 4, 6, 6, 4, 3, 5, 3, 6, 5, 3, 6, 4, 6, 6, 1, 7, 2, 5, 6, 3, 4, 6, 4, 6, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 8, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 6, 4, 6, 6, 4, 6, 4, 3, 6, 5, 4, 6, 4, 6, 6, 4, 6, 3, 5, 6, 3, 5, 3, 6, 5, 3, 4, 3, 3, 4, 5, 5, 4, 3, 1, 7, 6, 7, 3, 3, 3, 4, 5, 5, 7, 7, 6, 7, 7, 3, 6, 3, 5, 3, 2, 7, 4, 7, 7, 7, 5, 1, 7, 2, 5, 3, 6, 3, 7, 7, 3, 7, 7, 7, 3, 3, 4, 3, 3, 7, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 3, 7, 7, 7, 3, 3, 4, 5, 4, 6, 3, 3, 7, 7, 7, 3, 3, 4, 3, 3, 4, 3, 3, 7, 7, 7, 3, 6, 3, 5, 2, 7, 2, 5, 6, 3, 6, 3, 6, 3, 7, 5, 3, 6, 5, 3, 4, 3, 5, 6, 2, 3, 4, 3, 1, 7, 6, 7, 1, 5, 5, 6, 3, 5, 7, 7, 6, 7, 7, 1, 6, 5, 1, 7, 2, 7, 4, 7, 2, 7, 3, 3, 7, 7, 7, 3, 6, 3, 5, 2, 6, 4, 6, 6, 4, 6, 4, 3, 6, 5, 3, 3, 7, 7, 7, 3, 3, 4, 3, 3, 6, 5, 1, 7, 2, 5, 6, 3, 4, 6, 3, 6, 5, 1, 7, 2, 5, 3, 6, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 7, 2, 3, 6, 5, 3, 4, 3, 5, 6, 3, 5, 6, 3, 1, 7, 6, 7, 1, 3, 3, 6, 5, 1, 7, 7, 6, 7, 7, 5, 4, 3, 3, 7, 7, 7, 4, 7, 2, 3, 4, 6, 4, 6, 6, 4, 6, 3, 5, 6, 4, 3, 3, 7, 7, 7, 3, 6, 3, 5, 3, 6, 5, 1, 7, 2, 5, 3, 6, 3, 3, 5, 6, 3, 5, 3, 6, 5, 3, 6, 4, 3, 5, 6, 3, 5, 3, 6, 5, 3, 3, 4, 3, 5, 6, 3, 5, 3, 2, 7, 5, 3, 4, 3, 5, 6, 3, 5, 7, 7, 6, 5, 3, 4, 3, 5, 6, 3, 2, 7, 3, 6, 5, 3, 4, 3, 5, 6, 5, 3, 5, 3, 6, 5, 3, 4, 3, 5, 6, 3, 3, 5, 3, 6, 5, 3, 4, 3, 3, 4, 6, 3, 5, 3, 6, 5, 3, 4, 6, 4, 5, 2, 7, 2, 5, 6, 3, 6, 3, 4, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 4, 3, 5, 6, 3, 5, 3, 2, 7, 4, 6, 7, 1, 3, 4, 5, 4, 3, 2, 3, 7, 6, 7, 1, 3, 4, 5, 5, 7, 5, 1, 7, 6, 7, 1, 3, 4, 3, 2, 6, 3, 1, 7, 6, 7, 1, 3, 6, 5, 3, 4, 3, 1, 7, 6, 7, 1, 5, 6, 5, 5, 4, 3, 1, 7, 6, 7, 3, 3, 3, 4, 5, 4, 3, 1, 7, 6, 4, 6, 2, 3, 5, 3, 6, 5, 3, 4, 3, 3, 7, 2, 7, 2, 5, 6, 3, 6, 3, 6, 5, 3, 4, 3, 5, 6, 3, 5, 7, 7, 3, 7, 6, 7, 1, 3, 4, 5, 5, 7, 4, 6, 6, 7, 7, 5, 5, 5, 5, 5, 3, 7, 7, 6, 7, 7, 5, 5, 4, 3, 5, 1, 7, 7, 6, 7, 7, 5, 3, 6, 6, 3, 5, 7, 7, 6, 7, 7, 1, 5, 3, 4, 5, 5, 7, 7, 6, 7, 7, 3, 5, 5, 5, 5, 5, 7, 7, 6, 6, 4, 7, 5, 5, 4, 3, 1, 7, 6, 7, 3, 7, 7, 5, 3, 6, 5, 3, 4, 3, 5, 6, 5, 3, 4, 3, 5, 6, 3, 2, 7, 5, 1, 7, 6, 7, 1, 3, 4, 3, 2, 3, 7, 7, 6, 7, 7, 5, 5, 4, 3, 4, 6, 6, 4, 7, 2, 3, 4, 5, 4, 3, 7, 7, 7, 4, 7, 2, 3, 5, 3, 5, 1, 7, 2, 7, 4, 7, 2, 7, 1, 6, 3, 5, 3, 2, 7, 4, 7, 7, 7, 3, 4, 5, 4, 3, 2, 7, 4, 6, 6, 2, 3, 4, 5, 5, 7, 7, 6, 7, 7, 7, 2, 3, 4, 3, 1, 7, 6, 7, 1, 3, 6, 5, 3, 4, 3, 5, 6, 5, 3, 6, 3, 1, 7, 6, 7, 1, 3, 6, 5, 5, 1, 7, 7, 6, 7, 7, 5, 3, 6, 3, 7, 7, 7, 4, 7, 2, 3, 5, 3, 4, 6, 6, 4, 6, 3, 5, 6, 3, 5, 3, 7, 7, 7, 3, 6, 3, 5, 2, 7, 5, 1, 7, 2, 5, 3, 6, 3, 7, 7, 6, 3, 5, 3, 6, 5, 3, 6, 4, 6, 5, 6, 3, 5, 3, 2, 7, 4, 7, 7, 3, 5, 6, 3, 5, 7, 7, 6, 7, 7, 5, 3, 6, 5, 3, 4, 3, 5, 6, 3, 3, 4, 3, 1, 7, 6, 7, 1, 5, 6, 6, 3, 5, 7, 7, 6, 7, 7, 1, 5, 5, 1, 7, 2, 7, 4, 7, 2, 7, 1, 3, 7, 7, 7, 3, 6, 3, 5, 2, 7, 4, 6, 6, 4, 6, 4, 3, 6, 5, 2, 3, 7, 7, 7, 3, 3, 4, 3, 3, 7, 5, 1, 7, 2, 5, 6, 3, 4, 6, 4, 6, 5, 1, 7, 2, 5, 3, 6, 3, 7, 3, 6, 5, 1, 7, 2, 7, 4, 7, 2, 3, 5, 3, 6, 5, 3, 4, 3, 3, 4, 5, 5, 4, 3, 1, 7, 6, 7, 3, 3, 3, 4, 5, 5, 7, 7, 6, 7, 7, 3, 6, 3, 5, 3, 2, 7, 4, 7, 7, 7, 5, 1, 7, 2, 5, 3, 6, 3, 7, 7, 3, 7, 7, 7, 3, 3, 4, 3, 3, 7, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 3, 7, 7, 7, 3, 3, 4, 5, 4, 6, 3, 3, 7, 7, 7, 3, 3, 4, 3, 3, 4, 3, 3, 7, 7, 7, 3, 6, 3, 5, 6, 3, 5, 3, 6, 5, 3, 4, 6, 4, 3, 4, 5, 4, 3, 1, 7, 6, 4, 6, 5, 5, 5, 5, 5, 7, 7, 6, 6, 4, 3, 4, 5, 4, 3, 2, 7, 4, 6, 6, 6, 3, 5, 3, 6, 5, 3, 6, 4, 6, 5, 1, 7, 2, 5, 6, 3, 4, 6, 4, 3, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 8, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 4, 6, 4, 6, 6, 4, 6, 4, 3, 6, 5, 2, 7, 2, 5, 6, 3, 6, 3, 4, 2, 3, 5, 3, 6, 5, 3, 4, 3, 3, 7, 5, 5, 4, 3, 1, 7, 6, 7, 3, 2, 3, 4, 5, 5, 7, 7, 6, 7, 7, 5, 6, 3, 5, 3, 2, 7, 4, 7, 7, 6, 5, 1, 7, 2, 5, 3, 6, 3, 7, 3, 3, 7, 7, 7, 3, 3, 4, 3, 3, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 3, 7, 7, 7, 3, 3, 4, 5, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 7, 2, 7, 2, 5, 6, 3, 6, 3, 6, 7, 7, 5, 3, 6, 5, 3, 4, 3, 5, 7, 2, 3, 4, 3, 1, 7, 6, 7, 1, 3, 5, 6, 3, 5, 7, 7, 6, 7, 7, 3, 6, 5, 1, 7, 2, 7, 4, 7, 2, 4, 3, 3, 7, 7, 7, 3, 6, 3, 5, 4, 6, 4, 6, 6, 4, 6, 4, 3, 6, 4, 3, 3, 7, 7, 7, 3, 3, 4, 3, 3, 6, 5, 1, 7, 2, 5, 6, 3, 4, 6, 3, 6, 5, 2, 7, 2, 5, 6, 3, 3, 6, 3, 6, 5, 2, 7, 2, 5, 3, 6, 3, 6, 3, 6, 5, 2, 7, 2, 7, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 3, 2, 7, 2, 5, 6, 3, 6, 3, 6, 3, 5, 2, 7, 2, 5, 6, 3, 6, 3, 4, 6, 5, 2, 7, 2, 5, 6, 3, 6, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 6, 3, 6, 5, 2, 7, 2, 5, 3, 6, 4, 3, 5, 6, 3, 5, 3, 6, 5, 3, 3, 4, 3, 5, 6, 3, 5, 3, 2, 6, 5, 3, 4, 3, 5, 6, 3, 5, 7, 5, 6, 5, 3, 4, 3, 5, 6, 3, 2, 2, 3, 6, 5, 3, 4, 3, 5, 6, 5, 7, 5, 3, 6, 5, 3, 4, 3, 5, 6, 2, 3, 5, 3, 6, 5, 3, 4, 3, 3, 5, 6, 3, 5, 3, 6, 5, 3, 4, 6, 3, 5, 2, 7, 2, 5, 6, 3, 6, 3, 6, 3, 6, 3, 6, 5, 2, 7, 2, 7, 3, 3, 4, 3, 5, 6, 3, 5, 3, 2, 6, 4, 6, 7, 1, 3, 4, 5, 4, 3, 3, 3, 7, 6, 7, 1, 3, 4, 5, 5, 6, 5, 1, 7, 6, 7, 1, 3, 4, 3, 5, 6, 3, 1, 7, 6, 7, 1, 3, 6, 2, 3, 4, 3, 1, 7, 6, 7, 1, 5, 7, 5, 5, 4, 3, 1, 7, 6, 7, 3, 2, 3, 4, 5, 4, 3, 1, 7, 6, 4, 7, 2, 3, 5, 3, 6, 5, 3, 4, 3, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 6, 5, 3, 4, 3, 5, 6, 3, 5, 7, 3, 3, 7, 6, 7, 1, 3, 4, 5, 5, 6, 4, 6, 6, 7, 7, 5, 5, 5, 5, 3, 3, 7, 7, 6, 7, 7, 5, 5, 4, 6, 5, 1, 7, 7, 6, 7, 7, 5, 3, 5, 6, 3, 5, 7, 7, 6, 7, 7, 1, 2, 3, 4, 5, 5, 7, 7, 6, 7, 7, 7, 5, 5, 5, 5, 5, 7, 7, 6, 6, 7, 7, 5, 5, 4, 3, 1, 7, 6, 7, 2, 5, 6, 3, 6, 3, 6, 5, 2, 7, 5, 6, 5, 3, 4, 3, 5, 6, 3, 2, 6, 5, 1, 7, 6, 7, 1, 3, 4, 3, 3, 3, 7, 7, 6, 7, 7, 5, 5, 4, 6, 4, 6, 6, 4, 7, 2, 3, 4, 5, 3, 3, 7, 7, 7, 4, 7, 2, 3, 5, 6, 5, 1, 7, 2, 7, 4, 7, 2, 7, 5, 6, 3, 5, 3, 2, 7, 4, 7, 7, 2, 3, 4, 5, 4, 3, 2, 7, 4, 6, 7, 2, 3, 4, 5, 5, 7, 7, 6, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 3, 2, 3, 6, 5, 3, 4, 3, 5, 6, 5, 5, 6, 3, 1, 7, 6, 7, 1, 3, 6, 6, 5, 1, 7, 7, 6, 7, 7, 5, 3, 3, 3, 7, 7, 7, 4, 7, 2, 3, 5, 6, 4, 6, 6, 4, 6, 3, 5, 6, 3, 3, 3, 7, 7, 7, 3, 6, 3, 5, 2, 6, 5, 1, 7, 2, 5, 3, 6, 3, 7, 5, 6, 3, 5, 3, 6, 5, 3, 6, 4, 3, 5, 6, 3, 5, 3, 2, 7, 4, 7, 2, 7, 2, 5, 6, 3, 6, 3, 6, 3, 7, 5, 3, 6, 5, 3, 4, 3, 5, 6, 2, 3, 4, 3, 1, 7, 6, 7, 1, 5, 5, 6, 3, 5, 7, 7, 6, 7, 7, 1, 6, 5, 1, 7, 2, 7, 4, 7, 2, 7, 3, 3, 7, 7, 7, 3, 6, 3, 5, 2, 6, 4, 6, 6, 4, 6, 4, 3, 6, 5, 3, 3, 7, 7, 7, 3, 3, 4, 3, 3, 6, 5, 1, 7, 2, 5, 6, 3, 4, 6, 3, 6, 5, 1, 7, 2, 5, 3, 6, 3, 5, 2, 7, 2, 5, 6, 3, 6, 3, 4, 2, 3, 5, 3, 6, 5, 3, 4, 3, 3, 7, 5, 5, 4, 3, 1, 7, 6, 7, 3, 2, 3, 4, 5, 5, 7, 7, 6, 7, 7, 5, 6, 3, 5, 3, 2, 7, 4, 7, 7, 6, 5, 1, 7, 2, 5, 3, 6, 3, 7, 3, 3, 7, 7, 7, 3, 3, 4, 3, 3, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 3, 7, 7, 7, 3, 3, 4, 5, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 3, 6, 5, 2, 7, 2, 5, 6, 3, 6, 4, 5, 6, 3, 5, 3, 6, 5, 3, 4, 6, 2, 3, 4, 5, 4, 3, 1, 7, 6, 4, 7, 5, 5, 5, 5, 5, 7, 7, 6, 6, 2, 3, 4, 5, 4, 3, 2, 7, 4, 6, 5, 6, 3, 5, 3, 6, 5, 3, 6, 4, 6, 5, 1, 7, 2, 5, 6, 3, 4, 6, 3, 3, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 8, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 5, 2, 7, 2, 5, 6, 3, 6, 3, 7, 2, 3, 5, 3, 6, 5, 3, 4, 3, 7, 7, 5, 5, 4, 3, 1, 7, 6, 7, 7, 2, 3, 4, 5, 5, 7, 7, 6, 7, 3, 5, 6, 3, 5, 3, 2, 7, 4, 7, 3, 6, 5, 1, 7, 2, 5, 3, 6, 3, 4, 3, 3, 7, 7, 7, 3, 3, 4, 3, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 5, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 6, 3, 6, 5, 2, 7, 2, 5, 6, 4, 3, 6, 3, 6, 5, 2, 7, 2, 5, 3, 6, 3, 6, 3, 6, 5, 2, 7, 2, 3, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 2, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 7, 2, 7, 2, 5, 6, 3, 6, 3, 6, 3, 5, 2, 7, 2, 5, 6, 3, 6, 3, 3, 6, 5, 2, 7, 2, 5, 6, 3, 6, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 4, 3, 6, 3, 6, 5, 2, 7, 2, 5, 4, 6, 4, 3, 5, 6, 3, 5, 3, 6, 4, 3, 3, 4, 3, 5, 6, 3, 5, 3, 3, 6, 5, 3, 4, 3, 5, 6, 3, 5, 3, 5, 6, 5, 3, 4, 3, 5, 6, 3, 7, 2, 3, 6, 5, 3, 4, 3, 5, 6, 7, 7, 5, 3, 6, 5, 3, 4, 3, 5, 7, 2, 3, 5, 3, 6, 5, 3, 4, 3, 3, 5, 6, 3, 5, 3, 6, 5, 3, 4, 3, 3, 4, 4, 4, 3, 3, 7, 7, 7, 3, 6, 3, 6, 3, 6, 5, 2, 7, 2, 4, 3, 3, 4, 3, 5, 6, 3, 5, 3, 4, 6, 4, 6, 7, 1, 3, 4, 5, 4, 4, 3, 3, 7, 6, 7, 1, 3, 4, 5, 3, 6, 5, 1, 7, 6, 7, 1, 3, 4, 3, 5, 6, 3, 1, 7, 6, 7, 1, 3, 7, 2, 3, 4, 3, 1, 7, 6, 7, 1, 7, 7, 5, 5, 4, 3, 1, 7, 6, 7, 7, 2, 3, 4, 5, 4, 3, 1, 7, 6, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 3, 5, 6, 3, 6, 3, 6, 5, 2, 7, 3, 6, 5, 3, 4, 3, 5, 6, 3, 5, 4, 3, 3, 7, 6, 7, 1, 3, 4, 5, 4, 6, 4, 6, 6, 7, 7, 5, 5, 5, 4, 3, 3, 7, 7, 6, 7, 7, 5, 5, 3, 6, 5, 1, 7, 7, 6, 7, 7, 5, 3, 5, 6, 3, 5, 7, 7, 6, 7, 7, 7, 2, 3, 4, 5, 5, 7, 7, 6, 7, 7, 7, 5, 5, 5, 5, 5, 7, 7, 6, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 2, 3, 5, 6, 5, 3, 4, 3, 5, 6, 3, 3, 6, 5, 1, 7, 6, 7, 1, 3, 4, 4, 3, 3, 7, 7, 6, 7, 7, 5, 5, 4, 6, 4, 6, 6, 4, 7, 2, 3, 4, 4, 3, 3, 7, 7, 7, 4, 7, 2, 3, 3, 6, 5, 1, 7, 2, 7, 4, 7, 2, 3, 5, 6, 3, 5, 3, 2, 7, 4, 7, 7, 2, 3, 4, 5, 4, 3, 2, 7, 4, 7, 7, 7, 3, 3, 4, 4, 4, 3, 3, 7, 7, 2, 5, 6, 3, 6, 3, 6, 5, 7, 2, 3, 6, 5, 3, 4, 3, 5, 6, 3, 5, 6, 3, 1, 7, 6, 7, 1, 3, 3, 6, 5, 1, 7, 7, 6, 7, 7, 5, 4, 3, 3, 7, 7, 7, 4, 7, 2, 3, 4, 6, 4, 6, 6, 4, 6, 3, 5, 6, 4, 3, 3, 7, 7, 7, 3, 6, 3, 5, 3, 6, 5, 1, 7, 2, 5, 3, 6, 3, 3, 5, 6, 3, 5, 3, 6, 5, 3, 6, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 7, 2, 7, 2, 5, 6, 3, 6, 3, 6, 7, 7, 5, 3, 6, 5, 3, 4, 3, 5, 7, 2, 3, 4, 3, 1, 7, 6, 7, 1, 3, 5, 6, 3, 5, 7, 7, 6, 7, 7, 3, 6, 5, 1, 7, 2, 7, 4, 7, 2, 4, 3, 3, 7, 7, 7, 3, 6, 3, 5, 4, 6, 4, 6, 6, 4, 6, 4, 3, 6, 4, 3, 3, 7, 7, 7, 3, 3, 4, 3, 3, 6, 5, 1, 7, 2, 5, 6, 3, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 4, 3, 5, 2, 7, 2, 5, 6, 3, 6, 3, 7, 2, 3, 5, 3, 6, 5, 3, 4, 3, 7, 7, 5, 5, 4, 3, 1, 7, 6, 7, 7, 2, 3, 4, 5, 5, 7, 7, 6, 7, 3, 5, 6, 3, 5, 3, 2, 7, 4, 7, 3, 6, 5, 1, 7, 2, 5, 3, 6, 3, 4, 3, 3, 7, 7, 7, 3, 3, 4, 3, 4, 6, 4, 6, 6, 4, 6, 4, 5, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 5, 4, 3, 3, 7, 7, 7, 3, 3, 4, 4, 3, 6, 5, 2, 7, 2, 5, 6, 3, 6, 3, 5, 6, 3, 5, 3, 6, 5, 3, 4, 7, 2, 3, 4, 5, 4, 3, 1, 7, 6, 7, 7, 5, 5, 5, 5, 5, 7, 7, 6, 7, 2, 3, 4, 5, 4, 3, 2, 7, 4, 3, 5, 6, 3, 5, 3, 6, 5, 3, 6, 3, 6, 5, 1, 7, 2, 5, 6, 3, 4, 4, 3, 3, 7, 7, 7, 3, 3, 4, 5, 4, 6, 4, 6, 6, 4, 6, 4, 5, 8 };

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

    int n_numbers;
    //cin >> n_numbers;
    read_int(n_numbers);

    for (int i = 0; i < n_numbers; ++i)
    {
        int num;
        //cin >> num;
        read_int(num);
        cout << iter_cache_arr[num] << '\n';
        //std::printf("%d\n", iter_cache_arr[num]);
    }

    return 0;
}
