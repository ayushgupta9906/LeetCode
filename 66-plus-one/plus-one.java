class Solution {
    public int[] plusOne(int[] digits) {

        StringBuilder sb = new StringBuilder();

        for (int d : digits) {
            sb.append(d);
        }

        java.math.BigInteger num = new java.math.BigInteger(sb.toString());

        num = num.add(java.math.BigInteger.ONE);

        String ans = num.toString();

        int[] result = new int[ans.length()];

        for (int i = 0; i < ans.length(); i++) {
            result[i] = ans.charAt(i) - '0';
        }

        return result;
    }
}