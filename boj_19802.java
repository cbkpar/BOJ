import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a,b,sz,i;
		while(st.hasMoreTokens()) {
			String str = st.nextToken();
			sz = str.length();
			a = b = 0;
			for(i=0;i<sz;i++) {
				if(str.charAt(i)=='\'') {
					a++;
				}else {
					break;
				}
			}
			for(i=sz-1;i>=0;i--) {
				if(str.charAt(i)=='\'') {
					b++;
				}else {
					break;
				}
			}
			for(i=a*2;i<sz-b*2;i++) sb.append(str.charAt(i));
		}
		System.out.println(sb);
	}
}
