class Solution {
public:
    int reverse(int x) {
        int rev = 0;  // This will hold the reversed number

        while (x != 0) {
            int pop = x % 10;  // Get the last digit (e.g., 123 % 10 = 3)
            x = x / 10;        // Remove the last digit (e.g., 123 / 10 = 12)

            // 🔴 Overflow Check:
            // If rev > INT_MAX / 10, multiplying it by 10 will already exceed limit.
            // If rev == INT_MAX / 10 and pop > 7, then rev * 10 + pop will overflow INT_MAX (2147483647)
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) {
                return 0;
            }

            // 🔴 Underflow Check:
            // If rev < INT_MIN / 10, multiplying it by 10 will underflow.
            // If rev == INT_MIN / 10 and pop < -8, then rev * 10 + pop will go below INT_MIN (-2147483648)
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) {
                return 0;
            }

            // ✅ No overflow/underflow → safe to proceed
            rev = rev * 10 + pop;  // Append digit to the reversed number
        }

        return rev;  // Final reversed number
    }
};
