import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,a,b;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			if(a==b) {
				if(a%2==0) {
					sb.append(a*2+"\n");
				}else {
					sb.append(a*2-1+"\n");
				}
			}else if(a-2==b) {
				if(a%2==0) {
					sb.append(a*2-2+"\n");
				}else {
					sb.append(a*2-3+"\n");
				}
			}else {
				sb.append("No Number\n");
			}
		}
		System.out.println(sb);
	}
}
