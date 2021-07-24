import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int r,g,t,i;
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		g = Integer.parseInt(st.nextToken());
		if(r>g) {
			t = gcd(g,r);
		}else {
			t = gcd(r,g);
		}
		for(i=1;i<=t;i++) if(t%i==0) sb.append(i+" "+(r/i)+" "+(g/i)+"\n");
		System.out.println(sb);
	}
	
	static int gcd(int a, int b) {
		if(b%a==0) return a;
		return gcd(b%a,a);
	}
}
