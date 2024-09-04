class Solution {
public:
    string reverseVowels(string s) {
        int left, right = s.size() - 1;
        char temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {

                left = i;
                while (right > left && !(s[right] == 'a' || s[right] == 'e' ||
                                         s[right] == 'i' || s[right] == 'o' ||
                                         s[right] == 'u' || s[right] == 'A' ||
                                         s[right] == 'E' || s[right] == 'I' ||
                                         s[right] == 'O' || s[right] == 'U')) {
                    right--;
                }

                if (left < right) {
                    temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                    right--;
                }
            }
        }
        return s;
    }
};
