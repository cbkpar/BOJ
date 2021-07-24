import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,s;
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			if(n==0&&m==0) break;
			s = 0;
			HashMap<Integer,Integer> cd = new HashMap<Integer,Integer>();
			while(n-->0) cd.put(Integer.parseInt(br.readLine()), 1);
			while(m-->0) if(cd.containsKey(Integer.parseInt(br.readLine()))) s++;
			sb.append(s+"\n");
		}
		System.out.println(sb);
	}
}
