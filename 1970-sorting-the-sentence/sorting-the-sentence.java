class Solution {
    public String sortSentence(String s) {
        int len=s.length();
        String[] words= s.split("\\s+");
        String[] res = new String[words.length];

        for(int i=0;i<words.length ;i++){
            char idx= words[i].charAt(words[i].length() - 1);
            int pos = idx - '0'-1;
            String val = words[i].substring(0,words[i].length()-1);
            res[pos]=val; 
        }

        StringBuilder r = new StringBuilder();
        for(String w : res){
            r.append(w).append(" ");
        }

        return r.toString().trim();
    }
}