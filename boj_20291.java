import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n;
		n = Integer.parseInt(br.readLine());
		TreeMap<String,Integer> map = new TreeMap<String,Integer>();
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine(),".");
			st.nextToken();
			String str = st.nextToken();
			if(map.containsKey(str)) {
				map.put(str,map.get(str)+1);
			}else {
				map.put(str,1);
			}
		}
		for(String ext:map.keySet()) sb.append(ext+" "+map.get(ext)+"\n");
		System.out.println(sb);
	}
}
