class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i = 1;
        int total = n;

        while(i < n) {

            // Equal ratings
            if(ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            // Increasing slope
            int peak = 0;

            while(i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                total += peak;
                i++;
            }

            // Decreasing slope
            int down = 0;

            while(i < n && ratings[i] < ratings[i - 1]) {
                down++;
                total += down;
                i++;
            }

            // Peak was counted twice
            total -= min(peak, down);
        }

        return total;
    }
};