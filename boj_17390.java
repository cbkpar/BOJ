import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i,s,e;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);
		int[] dp = new int[n+1];
		for(i=1;i<=n;i++) dp[i] = dp[i-1] + arr[i-1];
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken())-1;
			e = Integer.parseInt(st.nextToken());
			sb.append((dp[e]-dp[s])+"\n");
		}
		System.out.println(sb);
	}
}
