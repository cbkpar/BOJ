import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,sz,i;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			int[] arr = new int[26];
			StringTokenizer st = new StringTokenizer(br.readLine());
			String a = st.nextToken();
			sz = a.length();
			for(i=0;i<sz;i++) arr[a.charAt(i)-'a']++;
			String b = st.nextToken();
			sz = b.length();
			for(i=0;i<sz;i++) arr[b.charAt(i)-'a']--;
			boolean chk = true;
			for(i=0;i<26;i++) if(arr[i]!=0) chk = false;
			sb.append(a+" & "+b+" are "+(chk?"":"NOT ")+"anagrams.\n");
		}
		System.out.println(sb);
	}
}
