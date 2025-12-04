#include <stdio.h>
#include <stdlib.h>
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void bs(int *nums, int n, int target, int low, int high) {
    if (target > nums[n-1]) return;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            printf("%d\n", target);
            break;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    bs(nums, n, target + 2, 0, n - 1);
}
int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmpfunc);
    int initialtarget = (arr[0] % 2 == 0) ? arr[0] : arr[0] + 1;
    bs(arr, n, initialtarget, 0, n - 1);
    return 0;
}
