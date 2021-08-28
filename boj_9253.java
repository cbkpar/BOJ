import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a,b,c;
		a = br.readLine();
		b = br.readLine();
		c = br.readLine();
		if(KMP(a,c)&&KMP(b,c)) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}
	
	public static boolean KMP(String str, String pattern) {
		int[] pi = getPI(pattern);
		char[] s = str.toCharArray();
		char[] p = pattern.toCharArray();
		int sz = s.length;
		int psz = p.length;
		int j = 0;
		for(int i=0;i<sz;i++) {
			while(j>0&&s[i]!=p[j]) j = pi[j-1];
			if(s[i]==p[j]) {
				if(j==psz-1) {
					return true;
				}else {
					j++;
				}
			}
		}
		return false;
	}
	
	public static int[] getPI(String pattern) {
		char[]  p = pattern.toCharArray();
		int sz = p.length;
		int j = 0;
		int[] pi = new int[sz];
		for(int i=1;i<sz;i++) {
			while(j>0&&p[i]!=p[j]) j = pi[j-1];
			if(p[i]==p[j]) pi[i] = ++j;
		}
		return pi;
	}
}
