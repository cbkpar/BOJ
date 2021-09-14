import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		n = Integer.parseInt(br.readLine());
		long[] a = new long[n+1];
		long[] b = new long[n+1];
		for(i=1;i<=n;i++) {
			a[i] = Integer.parseInt(br.readLine());
			b[i] = a[i]*a[i];
		}
		for(i=1;i<=n;i++) {
			a[i] += a[i-1];
			b[i] += b[i-1];
		}
		long mx = 0;
		for(i=1;i<=n;i++) {
			mx = Math.max(mx, b[i]*(a[n]-a[i]));
		}
		System.out.println(mx);
	}
}
