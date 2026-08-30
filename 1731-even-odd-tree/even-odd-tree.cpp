class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {

            int size = q.size();

            // Previous value depends on the level
            int prev;

            if (level % 2 == 0)
                prev = 0;       // even level → increasing odd values
            else
                prev = INT_MAX; // odd level → decreasing even values

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                int val = node->val;

                // Even level
                if (level % 2 == 0) {

                    // Must be odd
                    if (val % 2 == 0)
                        return false;

                    // Must be strictly increasing
                    if (val <= prev)
                        return false;
                }

                // Odd level
                else {

                    // Must be even
                    if (val % 2 != 0)
                        return false;

                    // Must be strictly decreasing
                    if (val >= prev)
                        return false;
                }

                prev = val;

                // Add children
                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            level++;
        }

        return true;
    }
};