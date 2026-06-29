class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        for (int start = 0; start < n; start += 2 * k) {

            int left = start;
            int right = min(start + k - 1, n - 1);

            while (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }
        }

        return s;
    }
};