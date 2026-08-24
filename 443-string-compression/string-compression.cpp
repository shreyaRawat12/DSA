class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int i = 0;

        while (i < chars.size()) {

            char ch = chars[i];
            int count = 0;

            // Count consecutive same characters
            while (i < chars.size() && chars[i] == ch) {
                i++;
                count++;
            }

            // Write character
            chars[index++] = ch;

            // Write count
            if (count > 1) {
                string s = to_string(count);

                for (char c : s) {
                    chars[index++] = c;
                }
            }
        }

        return index;
    }
};