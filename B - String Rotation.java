import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.Map;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        
        String s = sc.nextLine();
        String t = sc.nextLine();
        
        String SS = s+s;
        
        if(SS.contains(t)){
          System.out.println("Yes");
        }else{
          System.out.println("No");
        }
        sc.close();
    }
}