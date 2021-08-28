import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,i,k,sz;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			ArrayList<String> arr = new ArrayList<String>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			while(st.hasMoreTokens()) arr.add(st.nextToken());
			String name = br.readLine();
			k = Integer.parseInt(br.readLine());
			sz = arr.size();
			for(i=0;i<sz;i++) {
				if(arr.get(i).equals(name)) {
					sb.append(arr.get((i+k-1)%sz)+"\n");
				}
			}
		}
		System.out.println(sb);
	}
}
