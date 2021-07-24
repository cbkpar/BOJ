import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i,sz;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			String str = br.readLine();
			sz = str.length();
			boolean chk = false;
			for(i=0;i<sz;i++) {
				if(str.charAt(i)==' ') {
					chk = true;
					sb.append(' ');
				}else if(str.charAt(i)==':'||str.charAt(i)=='-') {
					if(i!=0) if(!chk) sb.append(' ');
					sb.append(str.charAt(i));
					if(i<sz-1) if(str.charAt(i+1)!=' ') {
						sb.append(' ');
						chk = true;
					}
				}else {
					sb.append(str.charAt(i));
					chk = false;
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
