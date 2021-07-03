import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int sz,i,t;
		String str = br.readLine();
		sz = str.length();
		i = 0;
		if(sz%3==1) {
			i = 1;
			sb.append(str.charAt(0));
		}else if(sz%3==2) {
			i = 2;
			t = str.charAt(1)-'0';
			t += (str.charAt(0)-'0')*2;
			sb.append(t);
		}
		for(;i<sz;i+=3) {
			t = (str.charAt(i)-'0')*4;
			t += (str.charAt(i+1)-'0')*2;
			t += (str.charAt(i+2)-'0');
			sb.append(t);
		}
		System.out.println(sb);
	}
}
