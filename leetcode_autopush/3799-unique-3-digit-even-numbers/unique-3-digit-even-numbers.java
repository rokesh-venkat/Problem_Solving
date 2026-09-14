class Solution {
    public int totalNumbers(int[] digits) {
        int[] availablecount = new int[10];

        for(int d: digits){
            availablecount[d]++;
        }

        int validcount =0;

        for(int num=100;num<1000;num+=2){
            int hund = num/100;
            int ten = (num/10)%10;
            int one = num%10;

            int[] needcount = new int[10];
            needcount[hund]++;
            needcount[ten]++;
            needcount[one]++;

            boolean valid = true;
            for(int i=0;i<10;i++){
                if(availablecount[i]<needcount[i]){
                    valid = false;
                    break;
                }
            }

            if(valid){
                validcount++;
            }
        }

        return validcount;

    }
}