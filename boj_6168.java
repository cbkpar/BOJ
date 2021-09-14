import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,mx;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n+1];
		for(i=1;i<=n;i++) arr[i] = Integer.parseInt(br.readLine())%2;
		for(i=1;i<=n;i++) arr[i] += arr[i-1];
		if(arr[n]==0) {
			System.out.println("0");
			return;
		}
		mx = Integer.MAX_VALUE;
		for(i=1;i<=n;i++) mx = Math.min(mx, i-arr[i]+arr[n]-arr[i]);
		System.out.println(mx);
	}
}
