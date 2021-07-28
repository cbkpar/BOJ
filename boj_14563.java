import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,n,i,s;
		t = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(t-->0) {
			n = Integer.parseInt(st.nextToken());
			s = 0;
			for(i=1;i<n;i++) if(n%i==0) s+=i;
			if(s>n) {
				sb.append("Abundant\n");
			}else if(s==n) {
				sb.append("Perfect\n");
			}else {
				sb.append("Deficient\n");
			}
		}
		System.out.println(sb);
	}
}
