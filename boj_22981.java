import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		long k,mx;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Long.parseLong(st.nextToken());
		long[] arr = new long[n+1];
		st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);
		mx = 0;
		for(i=1;i<n;i++) {
			mx = Math.max(mx, arr[1]*i+arr[i+1]*(n-i));
		}
		if(k%mx==0) {
			System.out.println(k/mx);
		}else {
			System.out.println(k/mx+1);
		}
	}
}
