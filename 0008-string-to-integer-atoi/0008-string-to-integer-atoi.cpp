class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long num = 0;   // use long long to handle overflow
        int sign = 1;

        // 1️⃣ Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2️⃣ Step 2: Handle sign (+/-)
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3️⃣ Step 3: Convert digits
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // 4️⃣ Step 4: Handle overflow
            if (num * sign > INT_MAX) return INT_MAX;
            if (num * sign < INT_MIN) return INT_MIN;
            
            i++;
        }

        // 5️⃣ Step 5: Return result
        return (int)(num * sign);
    }
};
