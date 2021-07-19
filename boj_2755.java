import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,s,t;
		double cpa;
		n = Integer.parseInt(br.readLine());
		s = 0;
		cpa = 0;
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			st.nextToken();
			t = Integer.parseInt(st.nextToken());
			s += t;
			String str = st.nextToken();
			if(str.equals("F")) continue;
			cpa += t * ('E' - str.charAt(0));
			if(str.charAt(1)=='+') cpa += 0.3 * (double)t;
			if(str.charAt(1)=='-') cpa -= 0.3 * (double)t;
		}
		System.out.printf("%.2f",cpa/(double)s);
	}
}
