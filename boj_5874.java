import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,s,t,i;
		String str = br.readLine();
		sz = str.length();
		s = t = 0;
		for(i=1;i<sz;i++) {
			if(str.charAt(i)=='('&&str.charAt(i-1)=='(') t++;
			if(str.charAt(i)==')'&&str.charAt(i-1)==')') s += t;
		}
		System.out.println(s);
	}
}
