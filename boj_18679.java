import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m;
		n = Integer.parseInt(br.readLine());
		HashMap<String,String> map = new HashMap<String,String>();
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			st.nextToken();
			map.put(str,st.nextToken());
		}
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			m = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			while(m-->0) {
				sb.append(map.get(st.nextToken())+" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
