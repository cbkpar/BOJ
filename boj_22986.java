import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t;
		long n,k;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Long.parseLong(st.nextToken());
			k = Long.parseLong(st.nextToken());
			if(k>n) k = n;
			sb.append((n*(n+1)-(n-k-1)*(n-k))*2+"\n");
		}
		System.out.println(sb);
	}
}
