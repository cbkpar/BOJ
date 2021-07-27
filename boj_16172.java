import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str1 = br.readLine().replaceAll("[0-9]", "");
		String str2 = br.readLine();
		System.out.println(KMP(str1,str2));
	}
	
	static int KMP(String str, String pattern) {
		int[] pi = PI(pattern);
		char[] s = str.toCharArray();
		char[] p = pattern.toCharArray();
		int j = 0;
		int sz = str.length();
		for(int i=0;i<sz;i++) {
			while(j>0&&s[i]!=p[j]) j = pi[j-1];
			if(s[i]==p[j]) {
				if(j==p.length-1) return 1;
				j++;
			}
		}
		return 0;
	}
	
	static int[] PI(String pattern) {
		int[] pi = new int[pattern.length()];
		char[] p = pattern.toCharArray();
		int j = 0;
		int sz = pattern.length();
		for(int i=1;i<sz;i++) {
			while(j>0&&p[i]!=p[j]) j = pi[j-1];
			if(p[i]==p[j]) pi[i] = ++j;
		}
		return pi;
	}
}
