#ifndef ALGORITHMS_MERGE_SORT_H__
#define ALGORITHMS_MERGE_SORT_H__

namespace algo {

    template <typename Comparable>
    static void merge(vector <Comparable> &range, int left, int right) {
        // temp array to store and merge the two sorted parts.
        vector<Comparable> temp;

        int mid = (left + right) / 2;
        int left_pos = left;
        int right_pos = mid + 1;

        while (left_pos <= mid && right_pos <= right) {
            if (range[left_pos] < range[right_pos]) {
                temp.push_back(range[left_pos++]);
            } else {
                temp.push_back(range[right_pos++]);
            }
        }
        while (left_pos <= mid) temp.push_back(range[left_pos++]);
        while (right_pos <= right) temp.push_back(range[right_pos++]);

        // copy back the sorted array to the original one.
	 for (int i = 0; i < temp.size(); ++i) {
            range[i + left] = temp[i];
        }

        return;
    }

    /**
     * This is a typical divide and conquer algorithm.
     * the running time is O(nlgn).
     * @tparam Comparable
     * @param range
     */
    template <typename Comparable>
    static void merge_sort(vector <Comparable> &range, int left, int right) {
        int mid = (left + right) / 2;
        if (left < right) {
            merge_sort(range, left, mid);
            merge_sort(range, mid + 1, right);
            merge(range, left, right);
        }
        return;
    }
}

#endif //ALGORITHMS_MERGE_SORT_H__