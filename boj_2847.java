import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,s;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(br.readLine());
		s = 0;
		for(i=n-2;i>=0;i--) {
			if(arr[i]>=arr[i+1]) {
				s += arr[i]-arr[i+1]+1;
				arr[i] = arr[i+1]-1;
			}
		}
		System.out.println(s);
	}
}
