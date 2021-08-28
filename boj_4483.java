import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,r,n,k,i;
		t = Integer.parseInt(br.readLine());
		for(r=1;r<=t;r++) {
			n = Integer.parseInt(br.readLine());
			String[] name = new String[n];
			for(i=0;i<n;i++) name[i] = br.readLine();
			k = Integer.parseInt(br.readLine());
			HashSet<String> part = new HashSet<String>();
			while(k-->0) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				while(st.hasMoreTokens()) part.add(st.nextToken());
			}
			if(r!=1) sb.append("\n");
			sb.append("Test set "+r+":\n");
			for(i=0;i<n;i++) sb.append(name[i]+" is "+(part.contains(name[i])?"present\n":"absent\n"));
		}
		System.out.println(sb);
	}
}
