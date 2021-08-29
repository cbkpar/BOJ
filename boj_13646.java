import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String str;
		int t;
		while((str=br.readLine())!=null) {
			t = Integer.parseInt(str);
			sb.append(eulerphi(t)/2+"\n");
		}
		System.out.println(sb);
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
