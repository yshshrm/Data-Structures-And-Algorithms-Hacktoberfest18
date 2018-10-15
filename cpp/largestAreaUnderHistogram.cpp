#include<iostream>
#include<climits>

int getMaxAmongThree(int a, int b, int c) {
    if(a >= b) {
        if(a >= c) {
            return a;
        }
        else {
            return c;
        }
    }
    else {
        if(b >= c) {
            return b;
        }
        else {
            return c;
        }
    }
}

int getMaxArea(int *arr, int left, int right) {
    if(left > right) {
        return INT_MIN;
    }
    if(left == right) {
        return arr[left];
    }
    int minElement = INT_MAX;
    int minIndex = 0;
    for(int i = left; i <= right; i++) {
        if(minElement > arr[i]) {
            minElement = arr[i];
            minIndex = i;
        }
    }
    return getMaxAmongThree(getMaxArea(arr, left, minIndex - 1), getMaxArea(arr, minIndex+1, right), (right - left + 1)*minElement);
}

int main() {
    int hist[] = {6, 1, 5, 4, 5, 2, 6};
    std::cout << getMaxArea(hist, 0, 6) << std::endl;
    return 0;
}