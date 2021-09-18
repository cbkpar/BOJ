import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,n,q,i,j,k,s,e,r;
		t = Integer.parseInt(br.readLine());
		for(i=1;i<=t;i++) {
			sb.append("Case #"+i+":\n");
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			q = Integer.parseInt(st.nextToken());
			long[] arr = new long[n+1];
			long[] dp = new long[(n*(n+1))/2+1];
			st = new StringTokenizer(br.readLine());
			for(j=1;j<=n;j++) arr[j] = arr[j-1] + Integer.parseInt(st.nextToken());
			r = 1;
			for(j=0;j<n;j++) {
				for(k=j+1;k<=n;k++) {
					dp[r++] = arr[k] - arr[j];
				}
			}
			Arrays.sort(dp);
			for(j=1;j<=(n*(n+1))/2;j++) dp[j] += dp[j-1];
			while(q-->0) {
				st = new StringTokenizer(br.readLine());
				s = Integer.parseInt(st.nextToken())-1;
				e = Integer.parseInt(st.nextToken());
				sb.append((dp[e]-dp[s])+"\n");
			}
		}
		System.out.println(sb);
	}
}
