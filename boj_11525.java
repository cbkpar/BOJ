import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,i;
		t = Integer.parseInt(br.readLine());
		int[] arr = new int[10001];
		arr[0] = 1;
		for(i=1;i<=10000;i++) arr[i] = arr[i-1] + eulerphi(i);
		for(i=1;i<=t;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			st.nextToken();
			sb.append(i+" "+arr[Integer.parseInt(st.nextToken())]+"\n");
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
