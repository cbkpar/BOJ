import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int n,t,i;
    	n = Integer.parseInt(br.readLine());
    	int[] dp = new int[n+1];
    	dp[0] = 1;
    	for(t=1;t<=n;t*=2) {
    		for(i=t;i<=n;i++) {
    			dp[i] = (dp[i] + dp[i-t])%1000000000;
    		}
    	}
    	System.out.println(dp[n]);
    }
}
