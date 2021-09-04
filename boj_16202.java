import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int[] par;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,k,i,j,cnt,s,e,score;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int[][] node = new int[m][2];
		for(i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			node[i][0] = Integer.parseInt(st.nextToken());
			node[i][1] = Integer.parseInt(st.nextToken());
		}
		for(i=0;i<k;i++) {
			par = new int[n+1];
			for(j=1;j<=n;j++) par[j] = j;
			score = cnt = 0;
			for(j=i;j<m;j++) {
				s = node[j][0];
				e = node[j][1];
				if(find(s)==find(e)) continue;
				cnt++;
				score += j+1;
				union(s,e);
			}
			if(cnt==n-1) {
				sb.append(score+" ");
			}else {
				sb.append("0 ");
			}
		}
		System.out.println(sb);
	}
	
	
	static int find(int x) {
		if(par[x]==x) return x;
		return par[x] = find(par[x]);
	}
	
	static void union(int a, int b) {
		int x = find(a);
		int y = find(b);
		par[y] = x;
	}
}
