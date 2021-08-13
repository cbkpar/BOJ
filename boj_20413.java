import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,s;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[4];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<4;i++) arr[i] = Integer.parseInt(st.nextToken());
		int[] dp = new int[n+1];
		String str = br.readLine();
		for(i=0;i<n;i++) {
			if(str.charAt(i)=='B') {
				dp[i+1] = arr[0]-dp[i]-1;
			}else if(str.charAt(i)=='S') {
				dp[i+1] = arr[1]-dp[i]-1;
			}else if(str.charAt(i)=='G') {
				dp[i+1] = arr[2]-dp[i]-1;
			}else if(str.charAt(i)=='P') {
				dp[i+1] = arr[3]-dp[i]-1;
			}else {
				dp[i+1] = arr[3];
			}
		}
		s = 0;
		for(i=0;i<=n;i++) s += dp[i];
		System.out.println(s);
	}
}
