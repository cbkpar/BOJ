import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int[] par;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,t,i,cnt;
		n = Integer.parseInt(br.readLine());
		par = new int[n+1];
		for(i=1;i<=n;i++) par[i] = i;
		m = Integer.parseInt(br.readLine());
		cnt = 0;
		while(m-->0) {
			t = find(Integer.parseInt(br.readLine()));
			if(t==0) break;
			union(t,t-1);
			cnt++;
		}
		System.out.println(cnt);
	}
	
	static int find(int x) {
		if(par[x]==x) return x;
		return par[x] = find(par[x]);
	}
	
	static void union(int a, int b) {
		a = find(a);
		b = find(b);
		par[a] = b;
	}
}
