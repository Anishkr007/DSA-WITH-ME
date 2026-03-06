class Solution {
public:
    bool isPalindrome(string s) {
        int left =0;
        int right = s.size();

        while(left < right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            else if(!isalnum(s[right])){
                right--;
                continue;
            }
            else{
                if(tolower(s[left])!=tolower(s[right])){
                    return false;
                }
                right--;
                left++;
            }
            
        }
        return true;
    }
};