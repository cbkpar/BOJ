import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int n,k,ans;
	static boolean[] chk;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i;
		n = Integer.parseInt(br.readLine());
		k = Integer.parseInt(br.readLine());
		chk = new boolean[n+1];
		dfs(1);
		chk[1] = true;
		ans = 0;
		for(i=1;i<=n;i++) if(chk[i]) ans++;
		System.out.println(ans);
	}
	
	public static void dfs(int t) {
		for(int i=2;i<=k;i++) {
			if(t*i>n) break;
			if(!chk[t*i]) {
				chk[t*i] = true;
				dfs(t*i);
			}
		}
	}
}
