import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,a,b,c;
		while(true) {
			n = Integer.parseInt(br.readLine());
			if(n==0) break;
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			if(a*c==b*b) {
				BigInteger r = new BigInteger(Integer.toString(b/a));
				BigInteger num = new BigInteger(Integer.toString(a));
				BigInteger sum = new BigInteger(Integer.toString(a));
				while(--n>0) {
					num = num.multiply(r);
					sum = sum.add(num);
				}
				sb.append(sum+"\n");
			}else {
				sb.append((n*(2*a+(n-1)*(b-a))/2)+"\n");
			}
		}
		System.out.println(sb);
	}
}
