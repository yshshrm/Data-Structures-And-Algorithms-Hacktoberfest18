#ifndef ALGORITHMS_BUBBLE_SORT_H
#define ALGORITHMS_BUBBLE_SORT_H

namespace algo {
    /**
     * runnig time of bubble sort is O(n^2)
     * @tparam Comparable
     * @param range
     */
    template <typename Comparable>
    static void bubble_sort(vector <Comparable> &range) {
        bool swapped = true;
        while(swapped) {
            swapped = false;
            for (int i = 1; i < range.size() - 2; ++i) {
                if (range[i + 1] < range[i]) {
                    swap(range[i + 1], range[i]);
                    swapped = true;
                }
            }
        }
    }
}

#endif //ALGORITHMS_BUBBLE_SORT_H