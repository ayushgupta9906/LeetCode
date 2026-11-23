import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            char currentChar = s.charAt(right);
            
            // Shrink window from the left until the duplicate character is removed
            while (set.contains(currentChar)) {
                set.remove(s.charAt(left));
                left++;
            }
            
            // Add current character to window set and compute max length
            set.add(currentChar);
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
}