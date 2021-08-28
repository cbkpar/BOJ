import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a,b,c,m,p,i,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		a = Integer.parseInt(st.nextToken());
		b = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		t = p = 0;
		for(i=0;i<24;i++) {
			if(p+a>m) {
				p = Math.max(p-c,0);
			}else {
				p += a;
				t += b;
			}
		}
		System.out.println(t);
	}
}
