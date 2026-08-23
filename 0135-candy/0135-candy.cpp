class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i = 1;
        int total = 1;

        while(i < n) {

            // Increasing
            int peak = 0;

            while(i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                total += peak;
                i++;
            }

            // Decreasing
            int down = 0;

            while(i < n && ratings[i] < ratings[i - 1]) {
                down++;
                total += down;
                i++;
            }

            // Peak needs max(up, down)
            total += max(peak, down);

            // Equal ratings
            if(i < n && ratings[i] == ratings[i - 1]) {
                total++;
                i++;
            }
        }

        return total;
    }
};