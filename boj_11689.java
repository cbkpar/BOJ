import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i,sq;
		long n,ans;
		ans = n = Long.parseLong(br.readLine());
		sq = (int)Math.sqrt(n);
		for(i=2;i<=sq;i++) {
			if(n%i==0) {
				ans /= i;
				ans *= i-1;
				while(n%i==0) n/=i;
			}
		}
		if(n!=1) {
			ans /= n;
			ans*= n-1;
		}
		System.out.println(ans);
	}
}
