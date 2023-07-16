

class Solution {
public:
    string minWindow(string s, string t) {
   // Check if the input strings are empty
    if (s.empty() || t.empty()) {
        return "";
    }

    std::unordered_map<char, int> target_counts;
    for (char c : t) {
        target_counts[c]++;
    }

    int required_chars = target_counts.size();
    int formed_chars = 0;
    int left = 0;
    int right = 0;

    std::unordered_map<char, int> window_counts;
    int min_window_size = INT_MAX;
    int min_window_left = 0;
    int min_window_right = 0;

    while (right < s.length()) {
        char c = s[right];
        window_counts[c]++;

        if (target_counts.count(c) && window_counts[c] == target_counts[c]) {
            formed_chars++;
        }

        while (left <= right && formed_chars == required_chars) {
            // Update the minimum window size and boundaries
            int current_window_size = right - left + 1;
            if (current_window_size < min_window_size) {
                min_window_size = current_window_size;
                min_window_left = left;
                min_window_right = right;
            }

            // Shrink the window from the left
            char left_char = s[left];
            window_counts[left_char]--;
            if (target_counts.count(left_char) && window_counts[left_char] < target_counts[left_char]) {
                formed_chars--;
            }

            left++;
        }

        right++;
    }

    if (min_window_size == INT_MAX) {
        return "";
    }

    return s.substr(min_window_left, min_window_size);
    }
};


