#include <iostream>
#include <vector>

int findUnsortedSubarrayLength(const std::vector<int>& nums) {
    int n = nums.size();
    
    // 找到开始不匹配的位置
    int start = 0;
    while (start < n - 1 && nums[start] <= nums[start + 1]) {
        start++;
    }

    // 如果整个序列都是有序的，返回0
    if (start == n - 1) {
        return 0;
    }

    // 找到结束不匹配的位置
    int end = n - 1;
    while (end > 0 && nums[end] >= nums[end - 1]) {
        end--;
    }

    // 找到中间打乱的序列的最小值和最大值
    int min_val = nums[start];
    int max_val = nums[end];
    for (int i = start; i <= end; i++) {
        min_val = std::min(min_val, nums[i]);
        max_val = std::max(max_val, nums[i]);
    }

    // 找到开始不匹配的位置之前的第一个比中间序列最小值大的位置
    while (start >= 0 && nums[start] > min_val) {
        start--;
    }

    // 找到结束不匹配的位置之后的第一个比中间序列最大值小的位置
    while (end < n && nums[end] < max_val) {
        end++;
    }

    // 返回中间打乱的序列的长度
    return end - start - 1;
}

int main() {
    // 示例用法
    std::vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    int result = findUnsortedSubarrayLength(nums);

    std::cout << "Length of unsorted subarray: " << result << std::endl;

    return 0;
}
