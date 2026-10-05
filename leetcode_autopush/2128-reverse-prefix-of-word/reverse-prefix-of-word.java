class Solution {
    public String reversePrefix(String word, char ch) {
        int end = word.indexOf(ch);
        if(end==-1) return word;
        StringBuilder sb = new StringBuilder();
        sb.append(word.substring(0,end+1));
        sb.reverse();
        sb.append(word.substring(end+1));

        return sb.toString();
    }
}