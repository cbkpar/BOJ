import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,k,m,mx,t,s;
		String str, ans;
		n = Integer.parseInt(br.readLine());
		ans = "";
		mx = s = 0;
		while(n-->0) {
			str = br.readLine();
			StringTokenizer st = new StringTokenizer(br.readLine());
		    k = Integer.parseInt(st.nextToken());
		    m = Integer.parseInt(st.nextToken());
			t = 0;
			while(m>=k) {
				t += m/k;
				m = m%k + (m/k)*2;
			}
			s += t;
			if(t>mx) {
				mx = t;
				ans = str;
			}
		}
		System.out.println(s+"\n"+ans);
	}
}
