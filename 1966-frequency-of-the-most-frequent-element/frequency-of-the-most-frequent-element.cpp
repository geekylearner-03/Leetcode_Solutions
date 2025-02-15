class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxFrequency = 0; // Initialize the maximum frequency
        long currentSum = 0; // Initialize the current sum of the subarray elements

        sort(nums.begin(), nums.end()); // Sort the array in ascending order

        for (int left = 0, right = 0; right < nums.size(); ++right) {
            currentSum += nums[right]; // Include the current element in the subarray sum

            // Check if the current subarray violates the condition (sum + k < nums[right] * length)
            while (currentSum + k < (long long)(nums[right]) * (right - left + 1)) {
                currentSum -= nums[left]; // Adjust the subarray sum by removing the leftmost element
                left++; // Move the left pointer to the right
            }

            // Update the maximum frequency based on the current subarray length
            maxFrequency = max(maxFrequency, right - left + 1);
        }

        return maxFrequency;
    }
};