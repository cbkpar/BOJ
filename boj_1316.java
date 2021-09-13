import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cnt,n,i,j,sz;
		n = Integer.parseInt(br.readLine());
		cnt = 0;
		for(i=0;i<n;i++) {
			String str = br.readLine();
			boolean[] chk = new boolean[26];
			chk[str.charAt(0)-'a'] = true;
			sz = str.length();
			for(j=1;j<sz;j++) {
				if(str.charAt(j)!=str.charAt(j-1)) {
					if(chk[str.charAt(j)-'a']) {
						break;
					}else {
						chk[str.charAt(j)-'a'] = true;
					}
				}
			}
			if(j==sz) cnt++;
		}
		System.out.println(cnt);
	}
}
