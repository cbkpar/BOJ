import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,s,t,a,b;
		while(true) {
			n = Integer.parseInt(br.readLine().trim());
			if(n==-1) break;
			t = s = 0;
			while(n-->0) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				s += a * (b-t);
				t = b;
			}
			sb.append(s+" miles\n");
		}
		System.out.println(sb);
	}
}
