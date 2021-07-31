import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		double a,d,k,s,t,m;
		StringTokenizer st = new StringTokenizer(br.readLine());
		t = a = Double.parseDouble(st.nextToken());
		d = Double.parseDouble(st.nextToken())/100.0;
		m = 1;
		k = Double.parseDouble(st.nextToken())/100.0;
		s = 0;
		while(true) {
			if(d>=1) {
				s += t*m;
				break;
			}else {
				s += t*d*m;
				m *= (1.0-d);
				d *= (1.0+k);
			}
			t += a;
		}
		System.out.println(s);
	}
}
