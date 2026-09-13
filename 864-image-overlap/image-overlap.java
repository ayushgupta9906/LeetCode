import java.util.ArrayList;
import java.util.List;

class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        List<int[]> ones1 = new ArrayList<>();
        List<int[]> ones2 = new ArrayList<>();

        // Step 1: Collect coordinates of all 1s in both images
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (img1[r][c] == 1) {
                    ones1.add(new int[]{r, c});
                }
                if (img2[r][c] == 1) {
                    ones2.add(new int[]{r, c});
                }
            }
        }

        // Step 2: Use a 2D array to count the frequency of each translation offset (dr, dc)
        // Offset ranges for dr and dc are from -(n-1) to (n-1).
        // Adding n shifts the range to [1, 2n-1], so a size of 2*n + 1 is sufficient.
        int[][] offsetCount = new int[2 * n + 1][2 * n + 1];
        int maxOverlap = 0;

        // Step 3: Compute translation vectors between every pair of 1s
        for (int[] p1 : ones1) {
            for (int[] p2 : ones2) {
                int dr = p2[0] - p1[0];
                int dc = p2[1] - p1[1];
                
                offsetCount[dr + n][dc + n]++;
                maxOverlap = Math.max(maxOverlap, offsetCount[dr + n][dc + n]);
            }
        }

        return maxOverlap;
    }
}