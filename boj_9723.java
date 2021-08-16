import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int i,t,a,b,c;
		t = Integer.parseInt(br.readLine());
		for(i=1;i<=t;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			sb.append("Case #"+i+": "+chk(a,b,c));
		}
		System.out.println(sb);
	}
	
	public static String chk(int a, int b, int c) {
		if(b>a&&b>c) {
			b^=c;
			c^=b;
			b^=c;
		}else if(a>b&&a>c) {
			a^=c;
			c^=a;
			a^=c;
		}
		if(c*c==a*a+b*b) return "YES \n";
		return "NO \n";
	}
}
