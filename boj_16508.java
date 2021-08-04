import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int[] t = new int[26];
	static int[] tmp = new int[26];
	static int[][] arr;
	static int[] cost;
	static int n,ans,sum;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] str = br.readLine().toCharArray();
		for(char c:str) t[c-'A']++;
		n = Integer.parseInt(br.readLine());
		arr = new int[n][26];
		cost = new int[n];
		for(int i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			cost[i] = Integer.parseInt(st.nextToken());
			str = st.nextToken().toCharArray();
			for(char c:str) arr[i][c-'A']++;
		}
		ans = Integer.MAX_VALUE;
		sum = 0;
		dfs(0);
		System.out.println(ans==Integer.MAX_VALUE?"-1":ans);
	}
	
	static void dfs(int k) {
		if(k==n) {
			boolean chk = true;
			for(int i=0;i<26;i++) if(tmp[i]<t[i]) chk = false;
			if(chk) ans = Math.min(ans, sum);
			return;
		}
		for(int i=0;i<26;i++) tmp[i] += arr[k][i];
		sum += cost[k];
		dfs(k+1);
		for(int i=0;i<26;i++) tmp[i] -= arr[k][i];
		sum -= cost[k];
		dfs(k+1);
	}
}
