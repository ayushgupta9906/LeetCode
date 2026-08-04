class Solution {
    public int oddEvenJumps(int[] arr) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int[] greaterThan = new int[arr.length];
        int[] lesserThan = new int[arr.length];
        
        for (int i = arr.length - 1; i >= 0; i--) {
            int val = arr[i];
            greaterThan[i] = 
                map.ceilingKey(val) != null ? map.get(map.ceilingKey(val)) : 0;
            lesserThan[i] = map.floorKey(val) != null ? map.get(map.floorKey(val)) : 0;
            map.put(val, i);
        }
        int ans = 0;
        Boolean memo[][] = new Boolean[arr.length][2];
        
        for (int i = arr.length - 1; i >= 0; i--) {
            
            if (recur(arr, greaterThan, lesserThan, i, 1, memo)) {
                ans++;
            }
        }
        return ans;
    }
    
    private boolean recur(int[] arr, int[] greaterThan, int[] lesserThan, int i, 
                          int jump, Boolean[][] memo) {
        
        if (i == arr.length - 1) {
            return true;
        }
        
        if (memo[i][jump] != null) {
            return memo[i][jump];
        }
        //odd Jump
        if (jump == 1) {
            
            if (arr[i] <= arr[greaterThan[i]] && i < greaterThan[i]) {
                return memo[i][jump] = 
                    recur(arr, greaterThan, lesserThan, greaterThan[i], jump ^ 1, memo);
            }
        } else {
            
            if (arr[i] >= arr[lesserThan[i]] && i < lesserThan[i]) {
                return memo[i][jump] = 
                    recur(arr, greaterThan, lesserThan, lesserThan[i], jump ^ 1, memo);
            }
        }
        return memo[i][jump] = false;
    }
}