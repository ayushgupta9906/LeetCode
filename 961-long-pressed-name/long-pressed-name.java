class Solution {
    public boolean isLongPressedName(String name, String typed) {

        int i = 0, j = 0;

        while (i < name.length()) {

            if (j >= typed.length() || name.charAt(i) != typed.charAt(j))
                return false;

            char ch = name.charAt(i);

            int nameCount = 0;
            while (i < name.length() && name.charAt(i) == ch) {
                nameCount++;
                i++;
            }

            int typedCount = 0;
            while (j < typed.length() && typed.charAt(j) == ch) {
                typedCount++;
                j++;
            }

            if (typedCount < nameCount)
                return false;
        }

        return j == typed.length();
    }
}