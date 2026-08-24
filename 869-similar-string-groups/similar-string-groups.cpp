class Solution {
public:

    bool similar(string &a, string &b) {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) {

            if (a[i] != b[i]) {
                diff++;

                if (diff > 2)
                    return false;
            }
        }

        return diff == 0 || diff == 2;
    }

    void dfs(int node, vector<string>& strs, vector<bool>& visited) {

        visited[node] = true;

        for (int i = 0; i < strs.size(); i++) {

            if (!visited[i] && similar(strs[node], strs[i])) {
                dfs(i, strs, visited);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        vector<bool> visited(n, false);

        int groups = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                groups++;

                dfs(i, strs, visited);
            }
        }

        return groups;
    }
};