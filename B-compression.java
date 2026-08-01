import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int N= input.nextInt();
		TreeSet<Integer> result = new TreeSet<>();
		for(int i = 0;i<N;i++){
			int temp = input.nextInt();
			result.add(temp);
		}
		
		System.out.println(result.size());
		for(int num : result){
			System.out.print(num+" ");
		}
	}
}