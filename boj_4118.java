import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i;
		while(true) {
			n = Integer.parseInt(br.readLine());
			if(n==0) break;
			boolean[] chk = new boolean[50];
			while(n-->0) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(i=0;i<6;i++) chk[Integer.parseInt(st.nextToken())] = true;
			}
			for(i=1;i<=49;i++) if(!chk[i]) break;
			sb.append(i==50?"Yes\n":"No\n");
		}
		System.out.println(sb);
	}
}
