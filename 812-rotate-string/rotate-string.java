class Solution {
    public boolean rotateString(String s, String goal) {
        String combined= s+s;
        return s.length()== goal.length() && combined.contains(goal);
    }
}