import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,ans,i,sq,t;
		n = Integer.parseInt(br.readLine());
		sq = (int)Math.sqrt(n);
		ans = Integer.MAX_VALUE;
		for(i=1;i<=sq;i++) {
			if(n%i==0) {
				t = eulerphi(i);
				if(t*i==n) ans = Math.min(ans, i);
				t = eulerphi(n/i);
				if(t*(n/i)==n) ans = Math.min(ans, (n/i));
			}
		}
		System.out.println(ans==Integer.MAX_VALUE?"-1":ans);
	}
	
	public static int eulerphi(int n) {
		int ans,sq,i;
		ans = n;
		sq = (int)Math.sqrt(ans);
		for(i=2;i<=sq;i++) {
			if(n%i==0) {
				ans /= i;
				ans *= i-1;
				while(n%i==0) n/=i;
			}
		}
		if(n!=1) {
			ans /= n;
			ans *= n-1;
		}
		return ans;
	}
}
