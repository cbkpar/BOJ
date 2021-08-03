import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int[] arr;
	static int n,m,ans;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n+1];
		st = new StringTokenizer(br.readLine());
		for(int i=1;i<=n;i++) arr[i] = Integer.parseInt(st.nextToken());
		ans = 0;
		dfs(1,0,0);
		System.out.println(ans);
	}
	
	static void dfs(int sz, int k, int t) {
		ans = Math.max(ans, sz);
		if(t<m) {
			if(k+1<=n) dfs(sz+arr[k+1],k+1,t+1);
			if(k+2<=n) dfs(sz/2+arr[k+2],k+2,t+1);
		}
	}
}
