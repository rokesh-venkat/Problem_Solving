import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int N= input.nextInt();
		int arr[] = new int[N+1];
		for(int i =1;i<=N;i++){
			arr[i]=input.nextInt();
		}
		int same=0;
		int exc=0;
		
		for(int i=1;i<=N;i++){
			if(i==arr[i]) same++;
			else if(i==arr[arr[i]]) exc++;
		}
		exc/=2;
		System.out.println(exc+1L*same*(same-1)/2);
	}
}