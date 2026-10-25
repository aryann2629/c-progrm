#include <stdio.h>

#define MAX 100

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[MAX], n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in ASCENDING order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result == -1) {
        printf("%d is not found in the array.\n", key);
    } else {
        printf("%d found at index %d (position %d).\n", key, result, result + 1);
    }
    return 0;
}
