class Solution {
private:
    int m, n;
    int remaining;
    unordered_map<int, int> mp; // maps random picks to real indices
    random_device rd;
    mt19937 gen;

public:
    Solution(int m, int n) : m(m), n(n), remaining(m * n), gen(rd()) {}

    vector<int> flip() {
        uniform_int_distribution<> dis(0, remaining - 1);
        int r = dis(gen);  // random index
        remaining--;

        // Find the mapped value or use itself
        int x = mp.count(r) ? mp[r] : r;

        // Move the last unflipped value to position r
        mp[r] = mp.count(remaining) ? mp[remaining] : remaining;

        // Convert back to (row, col)
        return {x / n, x % n};
    }

    void reset() {
        mp.clear();
        remaining = m * n;
    }
};