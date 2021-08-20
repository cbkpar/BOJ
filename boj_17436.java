import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static long ans,m,sign;
	static int n;
	static long[] arr;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Long.parseLong(st.nextToken());
		arr = new long[n];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Long.parseLong(st.nextToken());
		sign = 1;
		for(i=1;i<=n;i++) {
			btr(1,0,i);
			sign = sign * -1;
		}
		System.out.println(ans);
	}
	
	public static void btr(long s, int t, int k) {
		if(k==0) {
			ans += (m/s)*sign;
			return;
		}
		for(int i=t;i<n;i++) btr(s*arr[i],i+1,k-1);
	}
}
