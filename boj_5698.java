import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			char c = st.nextToken().toLowerCase().charAt(0);
			if(c=='*') break;
			boolean chk = true;
			while(st.hasMoreTokens()) if(st.nextToken().toLowerCase().charAt(0) != c) chk = false;
			sb.append(chk?"Y\n":"N\n");
		}
		System.out.println(sb);
	}
}
