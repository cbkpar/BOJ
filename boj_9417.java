import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,sz,i,j,m;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			ArrayList<Integer> arr = new ArrayList<Integer>();
			while(st.hasMoreTokens()) arr.add(Integer.parseInt(st.nextToken()));
			Collections.sort(arr);
			m = 0;
			sz = arr.size();
			for(i=0;i<sz-1;i++) {
				for(j=i+1;j<sz;j++) {
					m = Math.max(m, gcd(arr.get(i),arr.get(j)));
				}
			}
			sb.append(m+"\n");
		}
		System.out.println(sb);
	}
	
	public static int gcd(int a, int b) {
		if(b%a==0) return a;
		return gcd(b%a,a);
	}
}
