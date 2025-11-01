class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool digitAfterE = true;

        int n = s.size();
        int i = 0;

        // Trim leading spaces
        while (i < n && s[i] == ' ') i++;
        // Trim trailing spaces
        int j = n - 1;
        while (j >= 0 && s[j] == ' ') j--;

        // Validate the trimmed string
        for (; i <= j; i++) {
            char c = s[i];

            if (isdigit(c)) {
                digitSeen = true;
                if (eSeen) digitAfterE = true;
            }
            else if (c == '+' || c == '-') {
                // Sign allowed only at start or right after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                // Dot allowed only once and not after e/E
                if (dotSeen || eSeen) return false;
                dotSeen = true;
            }
            else if (c == 'e' || c == 'E') {
                // e/E allowed only once and must come after a digit
                if (eSeen || !digitSeen) return false;
                eSeen = true;
                digitAfterE = false;
            }
            else {
                return false;
            }
        }

        return digitSeen && digitAfterE;
    }
};
