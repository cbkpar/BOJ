import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		int k,c,n,m;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		k = Integer.parseInt(br.readLine());
		c = Integer.parseInt(br.readLine());
		while(c-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			if(n>=m) {
				if(n-2<=m+k-n) {
					sb.append("1\n");
				}else {
					sb.append("0\n");
				}
			}else {
				if(m-1<=n+k-m) {
					sb.append("1\n");
				}else {
					sb.append("0\n");
				}
			}
		}
		System.out.println(sb);
	}
}
