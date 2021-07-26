import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i,m;
		int[] arr = new int[26];
		sz = Integer.parseInt(br.readLine());
		String str = br.readLine();
		for(i=0;i<sz;i++) arr[str.charAt(i)-'a']++;
		m = 0;
		for(i=0;i<26;i++) m = Math.max(m, arr[i]);
		for(i=0;i<26;i++) if(arr[i]==m) {
			System.out.println((char)('a'+i)+" "+m);
			return;
		}
	}
}
