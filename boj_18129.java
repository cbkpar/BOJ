import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int sz,i,k,cnt;
		StringTokenizer st = new StringTokenizer(br.readLine());
		String str = st.nextToken().toLowerCase()+"#";
		k = Integer.parseInt(st.nextToken());
		boolean[] chk = new boolean[26];
		cnt = 1;
		sz = str.length();
		for(i=1;i<sz;i++) {
			if(str.charAt(i-1)!=str.charAt(i)) {
				if(!chk[str.charAt(i-1)-'a']) {
					chk[str.charAt(i-1)-'a'] = true;
					sb.append(cnt>=k?"1":"0");
				}
				cnt = 1;
			}else {
				cnt++;
			}
		}
		System.out.println(sb);
	}
}
