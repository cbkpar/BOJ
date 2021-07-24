import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n;
		long ans;
		ans = 0;
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(n-->0) {
			String str = st.nextToken();
			if(ispal(str)) ans += Integer.parseInt(str);
		}
		System.out.println(ans);
	}
	
	static boolean ispal(String str) {
		int sz = str.length();
		for(int i=0;i<sz/2;i++) if(str.charAt(i)!=str.charAt(sz-i-1)) return false;
		return true;
	}
}
