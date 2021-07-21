import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int sz,i,t;
		String str = br.readLine();
		sz = str.length();
		t = 0;
		for(i=0;i<sz;i++) {
			if(str.charAt(i)=='X') {
				t++;
				if(i!=sz-1) continue;
			}
			if(t%2==1) {
				System.out.println("-1");
				return;
			}
			while(t>=4) {
				t -= 4;
				sb.append("AAAA");
			}
			while(t>=2) {
				t -= 2;
				sb.append("BB");
			}
			if(str.charAt(i)=='.') sb.append(".");
		}
		System.out.println(sb);
	}
}
