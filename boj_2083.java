import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String str;
		int a,b;
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			str = st.nextToken();
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			if(str.equals("#")) break;
			if(a>17||b>=80) {
				sb.append(str+" Senior\n");
			}else {
				sb.append(str+" Junior\n");
			}
		}
		System.out.println(sb);
	}
}
