import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

public class Main {
    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> seen = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int cmp = target - nums[i];
            
            if (seen.containsKey(cmp)) {
                return new int[] { seen.get(cmp), i };
            }
            
            seen.put(nums[i], i);
        }
        
        return new int[] {-1,-1};
    }

    public static void main(String[] args) {
        // Test case
        //Scanner sc = new Scanner(System.in);
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        
        int[] result = twoSum(nums, target);
        
        // Print the result array
        System.out.println(Arrays.toString(result));
    }
}