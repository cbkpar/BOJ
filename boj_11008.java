import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			String pattern = st.nextToken();
			sb.append((str.length()-(pattern.length()-1)*KMP(str,pattern))+"\n");
		}
		System.out.println(sb);
	}
	
	static int KMP(String str, String pattern) {
		int[] pi = GETPI(pattern);
		char[] s = str.toCharArray();
		char[] p = pattern.toCharArray();
		int ssz = s.length;
		int psz = p.length;
		int j = 0;
		int ans = 0;
		for(int i=0;i<ssz;i++) {
			while(j>0&&s[i]!=p[j]) j = pi[j-1];
			if(s[i]==p[j]) {
				if(j==psz-1) {
					ans++;
					j = 0;
				}else {
					j++;
				}
			}
		}
		return ans;
	}
	
	static int[] GETPI(String pattern) {
		int sz = pattern.length();
		int[] pi = new int[sz];
		char[] p = pattern.toCharArray();
		int j = 0;
		for(int i=1;i<sz;i++) {
			while(j>0&&p[i]!=p[j]) j = pi[j-1];
			if(p[i]==p[j]) pi[i] = ++j;
		}
		return pi;
	}
}
