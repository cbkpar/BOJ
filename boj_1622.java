import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String str;
		int sz,i,j;
		while((str=br.readLine())!=null) {
			int[] a = new int[26];
			int[] b = new int[26];
			sz = str.length();
			for(i=0;i<sz;i++) a[str.charAt(i)-'a']++;
			str = br.readLine();
			sz = str.length();
			for(i=0;i<sz;i++) b[str.charAt(i)-'a']++;
			for(i=0;i<26;i++) for(j=Math.min(a[i], b[i]);j>0;j--) sb.append((char)(i+'a'));
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
