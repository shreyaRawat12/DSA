class FrontMiddleBackQueue {
private:
    deque<int> q;

public:
    FrontMiddleBackQueue() {
    }

    void pushFront(int val) {
        q.push_front(val);
    }

    void pushMiddle(int val) {
        int n = q.size();

        // Insert before the current middle
        int mid = n / 2;

        q.insert(q.begin() + mid, val);
    }

    void pushBack(int val) {
        q.push_back(val);
    }

    int popFront() {
        if (q.empty()) {
            return -1;
        }

        int val = q.front();
        q.pop_front();

        return val;
    }

    int popMiddle() {
        if (q.empty()) {
            return -1;
        }

        int n = q.size();

        // Frontmost middle
        int mid = (n - 1) / 2;

        int val = q[mid];
        q.erase(q.begin() + mid);

        return val;
    }

    int popBack() {
        if (q.empty()) {
            return -1;
        }

        int val = q.back();
        q.pop_back();

        return val;
    }
};