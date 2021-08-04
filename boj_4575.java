import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int sz,i;
		while(true) {
			String str = br.readLine();
			if(str.equals("END")) break;
			boolean[] chk = new boolean[26];
			sz = str.length();
			for(i=0;i<sz;i++) {
				if(str.charAt(i)>='A'&&str.charAt(i)<='Z') {
					if(chk[str.charAt(i)-'A']) {
						break;
					}else {
						chk[str.charAt(i)-'A'] = true;
					}
				}
			}
			if(i==sz) sb.append(str+"\n"); 
		}
		System.out.println(sb);
	}
}
