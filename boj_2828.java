import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,t,k,p,s;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(br.readLine());
		p = 1;
		s = 0;
		while(t-->0) {
			k = Integer.parseInt(br.readLine());
			if(k<p) {
				s += p-k;
				p = k;
			}else if(p+m-1<k) {
				s += k-p-m+1;
				p = k-m+1;
			}
		}
		System.out.println(s);
	}
}
