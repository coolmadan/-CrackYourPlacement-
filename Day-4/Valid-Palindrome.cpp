class Solution {
public:
    bool validPalindrome(string s) {
      int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                string s1 = s;
                s1.erase(s1.begin() + left);
                string s2 = s;
                s2.erase(s2.begin() + right);

                if (s1 == string(s1.rbegin(), s1.rend())) {
                    return true;
                }
                else if (s2 == string(s2.rbegin(), s2.rend())) {
                    return true;
                }
                else {
                    return false;
                }
            }

            left++;
            right--;
        }

        return true;
    
    }
};
