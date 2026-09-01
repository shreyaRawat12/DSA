class Solution {
public:

    bool checkPath(ListNode* head, TreeNode* root) {

        // Linked list completely match ho gayi
        if (head == nullptr)
            return true;

        // Tree khatam ho gaya but list abhi baaki hai
        if (root == nullptr)
            return false;

        // Values match nahi karti
        if (head->val != root->val)
            return false;

        // Next list node ko left ya right child se match karo
        return checkPath(head->next, root->left) ||
               checkPath(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {

        if (root == nullptr)
            return false;

        // Current node se path start karke dekho
        if (checkPath(head, root))
            return true;

        // Left subtree mein starting point try karo
        if (isSubPath(head, root->left))
            return true;

        // Right subtree mein starting point try karo
        return isSubPath(head, root->right);
    }
};