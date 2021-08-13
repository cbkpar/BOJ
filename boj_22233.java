import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m;
		HashSet<String> set = new HashSet<String>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		while(n-->0) {
			String str = br.readLine();
			if(!set.contains(str)) set.add(str);
		}
		while(m-->0) {
			st = new StringTokenizer(br.readLine(),",");
			while(st.hasMoreTokens()) {
				String str = st.nextToken();
				if(set.contains(str)) set.remove(str);
			}
			sb.append(set.size()+"\n");
		}
		System.out.println(sb);
	}
}
