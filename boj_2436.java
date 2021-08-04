import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a,b,sq,i;
		StringTokenizer st = new StringTokenizer(br.readLine());
		a = Integer.parseInt(st.nextToken());
		b = Integer.parseInt(st.nextToken());
		b /= a;
		sq = (int)Math.sqrt(b);
		for(i=sq;i>=1;i--) {
			if(b%i==0) {
				if(gcd(i,b/i)==1) {
					System.out.println((i*a)+" "+(b/i*a));
					return;
				}
			}
		}
	}
	static int gcd(int a, int b) {
		if(b%a==0) return a;
		return gcd(b%a,a);
	}
}
