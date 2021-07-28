import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,s,t,i;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			String str = br.readLine();
			s = 0;
			for(i=0;i<16;i++) {
				if(i%2==0) {
					t = (str.charAt(i)-'0')*2;
					s += t%10 + t/10;
				}else {
					s += str.charAt(i)-'0';
				}
			}
			if(s%10==0) {
				sb.append("T\n");
			}else {
				sb.append("F\n");
			}
		}
		System.out.println(sb);
	}
}
