import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,s,r,i,t,ans;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		s = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		boolean[] chk = new boolean[n+2];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<s;i++) chk[Integer.parseInt(st.nextToken())] = true;
		st = new StringTokenizer(br.readLine());
		for(i=0;i<r;i++) {
			t = Integer.parseInt(st.nextToken());
			if(chk[t]) {
				chk[t] = false;
			}else {
				if(chk[t-1]) {
					chk[t-1] = false;
				}else if(chk[t+1]) {
					chk[t+1] = false;
				}
			}
		}
		ans = 0;
		for(i=1;i<=n;i++) if(chk[i]) ans++;
		System.out.println(ans);
	}
}
