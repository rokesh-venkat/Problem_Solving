import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        // Fast I/O for competitive programming
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        
        Map<Integer, Integer> counts = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            // Increment the occurrence count for each number
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        
        int ans = 0;
        for (int count : counts.values()) {
            // If the count is odd, the number remains on the sheet
            if (count % 2 != 0) {
                ans++;
            }
        }
        
        System.out.println(ans);
    }
}