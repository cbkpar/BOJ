import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i,cnt,s;
		String str = br.readLine()+"#";
		sz = str.length();
		s = 0;
		cnt = 1;
		for(i=1;i<sz;i++) {
			if(str.charAt(i)-str.charAt(i-1)==1) {
				cnt++;
			}else {
				if(cnt==3) s++;
				cnt = 1;
			}
		}
		System.out.println(s);
	}
}
