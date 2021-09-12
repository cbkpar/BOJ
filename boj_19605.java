import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i;
		boolean chk = false;
		String str = br.readLine();
		String pattern = br.readLine();
		sz = pattern.length();
		for(i=0;i<sz;i++) {
			if(KMP(str,pattern.substring(i)+pattern.substring(0, i))) chk = true;
			if(chk) break;
		}
		System.out.println(chk?"yes":"no");
	}
	
	public static boolean KMP(String str, String Pattern) {
		char[] s = str.toCharArray();
		char[] p = Pattern.toCharArray();
		int[] pi  = getPI(Pattern);
		int j = 0;
		int sz = str.length();
		for(int i=0;i<sz;i++) {
			while(j>0&&s[i]!=p[j]) j = pi[j-1];
			if(s[i]==p[j]) {
				if(j==p.length-1) {
					return true;
				}else {
					j++;
				}
			}
		}
		return false;
	}
	
	
	public static int[] getPI(String str) {
		char[] p = str.toCharArray();
		int sz = str.length();
		int[] pi = new int[sz];
		int j = 0;
		for(int i=1;i<sz;i++) {
			while(j>0&&p[i]!=p[j]) j = pi[j-1];
			if(p[i]==p[j]) pi[i] = ++j;
		}
		return pi;
	}
}
