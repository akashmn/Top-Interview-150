// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105

// ##############################################################################################################################################

void rotate(int* nums, int numsSize, int k) {
    
    k = k % numsSize;
    int count = 0;
    int candidate = 0;
    for(int i = 0; i < numsSize; i++){
        if(count == 0){
            candidate = nums[i];
        }
        if(candidate == nums[i]){
            count++;
        }else{
            count--;
        }
    }
    int temp = 0;
    for(int i = 0; i < k; i++){
        temp = nums[numsSize - 1];
        for(int j = numsSize - 1; j > 0; j--){
            nums[j] = nums[j - 1];
        }
        nums[0] = temp;
    }
}

// ##############################################################################################################################################

void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}