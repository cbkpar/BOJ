import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m;
	static int[] arrs;
	static int[] arrb;

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i;
		n = Integer.parseInt(br.readLine());
		arrs = new int[n];
		arrb = new int[n];
		for(i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			arrs[i] = Integer.parseInt(st.nextToken());
			arrb[i] = Integer.parseInt(st.nextToken());
		}
		m = Integer.MAX_VALUE;
		dfs(1,0,0);
		System.out.println(m);
	}
	
	public static void dfs(int a, int b, int k) {
		if(k==n) {
			if(b!=0) m = Math.min(m, Math.abs(a-b));
			return;
		}
		dfs(a,b,k+1);
		dfs(a*arrs[k],b+arrb[k],k+1);
	}
}
