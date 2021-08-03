import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,n,k;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			HashMap<Integer,Boolean> map = new HashMap<Integer,Boolean>();
			n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			while(n-->0) {
				k = Integer.parseInt(st.nextToken());
				if(!map.containsKey(k)) map.put(k,true);
			}
			n = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			while(n-->0) sb.append(map.containsKey(Integer.parseInt(st.nextToken()))?"1\n":"0\n");
		}
		System.out.println(sb);
	}
}
