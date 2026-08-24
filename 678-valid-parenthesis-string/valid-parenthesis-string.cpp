class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (char c : s) {

            if (c == '(') {
                low++;
                high++;
            }

            else if (c == ')') {
                low--;
                high--;
            }

            else { // '*'
                low--;      // '*' as ')'
                high++;     // '*' as '('
            }

            // Minimum cannot be negative
            low = max(0, low);

            // Too many closing brackets
            if (high < 0)
                return false;
        }

        // We need possibility of zero unmatched '('
        return low == 0;
    }
};