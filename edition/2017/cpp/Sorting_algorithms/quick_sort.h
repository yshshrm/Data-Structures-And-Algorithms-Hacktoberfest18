#ifndef ALGORITHMS_QUICK_SORT_H__
#define ALGORITHMS_QUICK_SORT_H__

#include <istream>
#include <vector>

namespace algo {
    using namespace std;
    template <typename random_access_itr>
    static random_access_itr partitioning(random_access_itr p, random_access_itr r) {
        random_access_itr pivot = r;
        random_access_itr i = p - 1;
        for (random_access_itr j = p; j <= (r - 1); ++j) {
            if (*j < *pivot) {
                i++;
                swap(*j, *i);
            }
        }
        swap(*(i + 1), *pivot);
        return (i + 1);
    }

    template <typename random_access_itr>
    static void quick_sort(random_access_itr left, random_access_itr right) {
        if (distance(left, right) >= 1) {
            random_access_itr q = partitioning(left, right);
            quick_sort(q + 1, right);
            quick_sort(left, q - 1);
        }
        return;
    }
}

#endif //ALGORITHMS_QUICK_SORT_H__