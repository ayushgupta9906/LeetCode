public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLength = 0;
        
        // Map standard ASCII character values to their next 1-based index position
        int[] lastSeen = new int[256];
        
        for (int left = 0, right = 0; right < n; right++) {
            char currentChar = s.charAt(right);
            
            // Instantly skip left pointer past the last duplicate occurrence if inside current window
            left = Math.max(left, lastSeen[currentChar]);
            
            // Update maximum window size
            maxLength = Math.max(maxLength, right - left + 1);
            
            // Store 1-based index (right + 1) for current character
            lastSeen[currentChar] = right + 1;
        }
        
        return maxLength;
    }
}