import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,a,b;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			sb.append((a<=2&&b<=1)||(a<=1&&b<=2)?"Yes\n":"No\n");
		}
		System.out.println(sb);
	}
}
