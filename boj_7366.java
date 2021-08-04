import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i,m,s;
		n = Integer.parseInt(br.readLine());
		for(i=1;i<=n;i++) {
			s = 0;
			m = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			while(m-->0) if(st.nextToken().equals("sheep")) s++;
			if(i!=1) sb.append("\n");
			sb.append("Case "+i+": This list contains "+s+" sheep.\n");
		}
		System.out.println(sb);
	}
}
