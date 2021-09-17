import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		long mx;
		n = Integer.parseInt(br.readLine());
		long[] arr = new long[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
		mx = 0;
		for(i=2;i<n;i++) {
			mx = Math.max(mx, arr[i-1]+arr[n-1]-arr[i]+arr[i-1]);
			mx = Math.max(mx, arr[n]-arr[i]+arr[n]-arr[1]-arr[i]+arr[i-1]);
			mx = Math.max(mx, arr[i]-arr[1]+arr[n-1]-arr[i-1]);
		}
		System.out.println(mx);
	}
}
