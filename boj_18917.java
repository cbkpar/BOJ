import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,t,k;
		long s,x;
		n = Integer.parseInt(br.readLine());
		s = x = 0;
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			k = Integer.parseInt(st.nextToken());
			if(k==1) {
				t = Integer.parseInt(st.nextToken());
				s += t;
				x ^= t;
			}else if(k==2) {
				t = Integer.parseInt(st.nextToken());
				s -= t;
				x ^= t;
			}else if(k==3) {
				sb.append(s+"\n");
			}else {
				sb.append(x+"\n");
			}
		}
		System.out.println(sb);
	}
}
