import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,t,i;
		n = Integer.parseInt(br.readLine());
		boolean[] chk = new boolean[n+2];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) {
			t = Integer.parseInt(st.nextToken());
			if(t<=n) chk[t] = true;
		}
		for(i=1;i<=n+1;i++) {
			if(!chk[i]) {
				System.out.println(i);
				return;
			}
		}
	}
}
