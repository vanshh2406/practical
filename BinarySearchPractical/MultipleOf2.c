#include <stdio.h>
void printEvensBinaryStyle(int arr[], int left, int right) {
    if (left > right) return;
    int mid = left + (right - left) / 2;
    printEvensBinaryStyle(arr, left, mid - 1);
    if (arr[mid] % 2 == 0) {
        printf("%d ", arr[mid]);
    }
    printEvensBinaryStyle(arr, mid + 1, right);
}
int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("Multiples of 2 in the array (order depends on recursion):\n");
    printEvensBinaryStyle(arr, 0, n - 1);
    printf("\n");
    return 0;
}