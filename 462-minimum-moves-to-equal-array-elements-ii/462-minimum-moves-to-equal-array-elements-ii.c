int minMoves2(int* nums, int numsSize){
    sortArray(nums, numsSize);
    int left = 0;
    int right = numsSize-1;
    int mid = numsSize/2;
    int count = 0;
    while(left != mid || right != mid){
        if(left != mid) count += nums[mid]-nums[left++];
        if(right != mid) count += nums[right--]-nums[mid];
    }
    return count;
}

void sortArray(int* nums, int n){
    printf("%d", n);
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(nums[i] > nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}