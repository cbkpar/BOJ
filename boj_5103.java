import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,s;
		while(true) {
			String str = br.readLine();
			if(str.equals("#")) break;
			StringTokenizer st = new StringTokenizer(br.readLine());
			m = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(br.readLine());
			while(n-->0) {
				st = new StringTokenizer(br.readLine());
				if(st.nextToken().charAt(0)=='S') {
					s -= Integer.parseInt(st.nextToken());
					if(s<0) s = 0;
				}else {
					s += Integer.parseInt(st.nextToken());
					if(s>m) s = m;
				}
			}
			sb.append(str+" "+s+"\n");
		}
		System.out.println(sb);
	}
}
