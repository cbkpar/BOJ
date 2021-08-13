import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i,s,mx;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[4];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<4;i++) arr[i] = Integer.parseInt(st.nextToken());
		int[] dp = new int[n+1];
		String str = br.readLine();
		for(i=0;i<n-1;i++) {
			if(str.charAt(i)=='B') {
				mx = arr[0]-dp[i]-1;
			}else if(str.charAt(i)=='S') {
				mx = arr[1]-dp[i]-1;
			}else if(str.charAt(i)=='G') {
				mx = arr[2]-dp[i]-1;
			}else if(str.charAt(i)=='P') {
				mx = arr[3]-dp[i]-1;
			}else {
				mx = arr[3];
			}
			if(str.charAt(i+1)=='B') {
				dp[i+1] = Math.min(mx, arr[0]-1);
			}else if(str.charAt(i+1)=='S') {
				dp[i+1] = Math.min(mx, arr[1]-1);
			}else if(str.charAt(i+1)=='G') {
				dp[i+1] = Math.min(mx, arr[2]-1);
			}else if(str.charAt(i+1)=='P') {
				dp[i+1] = Math.min(mx, arr[3]-1);
			}else {
				dp[i+1] = mx;
			}
		}
		if(str.charAt(n-1)=='B') {
			dp[n] = arr[0]-dp[n-1]-1;
		}else if(str.charAt(n-1)=='S') {
			dp[n] = arr[1]-dp[n-1]-1;
		}else if(str.charAt(n-1)=='G') {
			dp[n] = arr[2]-dp[n-1]-1;
		}else if(str.charAt(n-1)=='P') {
			dp[n] = arr[3]-dp[n-1]-1;
		}else {
			dp[n] = arr[3];
		}
		s = 0;
		for(i=0;i<=n;i++) s += dp[i];
		System.out.println(s);
	}
}
