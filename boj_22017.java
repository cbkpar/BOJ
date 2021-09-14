import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,ans;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) arr[i] = Integer.parseInt(st.nextToken());
		for(i=1;i<=n;i++) arr[i] += arr[i-1];
		ans = Integer.MAX_VALUE;
		for(i=0;i<=n;i++) {
			ans = Math.min(ans, i-arr[i]+arr[n]-arr[i]);
		}
		System.out.println(ans);
	}
}
