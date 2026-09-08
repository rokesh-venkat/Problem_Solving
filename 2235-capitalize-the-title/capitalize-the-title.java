class Solution {
    public String capitalizeTitle(String title) {
        String[] words= title.split("\\s+");
        StringBuilder result= new StringBuilder();

        for(String w:words){
            if(w.length()<=2){
                result.append(w.toLowerCase());
            }else{
                result.append(Character.toUpperCase(w.charAt(0)))
                .append(w.substring(1).toLowerCase());
            }
            
            result.append(" ");
            
        }

        String res=result.toString();
        return res.trim();
    }

}