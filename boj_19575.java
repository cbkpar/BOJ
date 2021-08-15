import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,x,i;
		long ans = 0;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		for(i=0;i<=n;i++) {
			st = new StringTokenizer(br.readLine());
			ans *= x;
			ans += Integer.parseInt(st.nextToken());
			ans %= 1000000007;
		}
		System.out.println(ans);
	}
}
