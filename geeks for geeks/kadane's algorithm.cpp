#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxSubarraySum(int arr[], int n) {
    int minusCount = 0;
    int sum = 0, ans = 0;
    int minn = -1e9-10;
    for(int i=0;i<n;++i){
        if(arr[i]<0) ++minusCount;
        sum+=arr[i];
        if(ans < sum) ans = sum;
        if(sum<0) sum = 0;
        if(minn < arr[i]) minn = arr[i];
    }
    if(minusCount==n) return minn;
    return ans;
}

int main() {
    char ts[1001];
    fgets(ts, sizeof(ts), stdin);
    int t = atoi(ts);
    while (t--) {
        char *line = NULL;
        size_t len = 0;
        long read = getline(&line, &len, stdin);

        int *nums = (int *)malloc(1000000 * sizeof(int));
        int n = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            nums[n++] = atoi(token);
            token = strtok(NULL, " ");
        }
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
        }
        int ans = maxSubarraySum(arr, n);
        printf("%d\n", ans);

        printf("%s\n", "~");
        free(nums);
        free(line);
    }

    return 0; 
}