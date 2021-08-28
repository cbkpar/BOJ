import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,k,t,sz;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		String str = st.nextToken();
		t = str.length();
		sb.append(str);
		n--;
		while(n-->0) {
			str = st.nextToken();
			sz = str.length();
			if(t+sz>k) {
				sb.append("\n"+str);
				t = sz;
			}else {
				sb.append(" "+str);
				t += sz;
			}
		}
		System.out.println(sb);
	}
}
