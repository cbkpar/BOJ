import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static ArrayList<Integer>[] node;
	static int[][] dp;
	static boolean[] visited;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,s,e,i;
		n = Integer.parseInt(br.readLine());
		node = new ArrayList[n+1];
		for(i=1;i<=n;i++) node[i] = new ArrayList<>();
		dp = new int[n+1][2];
		visited = new boolean[n+1];
		for(i=1;i<=n;i++) Arrays.fill(dp[i], -1);
		while(--n>0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			node[s].add(e);
			node[e].add(s);
		}
		visited[1] = true;
		System.out.println(Math.min(dfs(1,0),dfs(1,1)));
	}
	
	public static int dfs(int s, int k) {
		if(dp[s][k]!=-1) return dp[s][k];
		int sz,i;
		sz = node[s].size();
		dp[s][k] = k;
		for(i=0;i<sz;i++) {
			if(visited[node[s].get(i)]) continue;
			visited[node[s].get(i)] = true;
			if(k==0) {
				dp[s][k] += dfs(node[s].get(i),1);
			}else {
				dp[s][k] += Math.min(dfs(node[s].get(i),0), dfs(node[s].get(i),1));
			}
			visited[node[s].get(i)] = false;
		}
		return dp[s][k];
	}
}
