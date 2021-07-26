import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,s,i;
		sz = Integer.parseInt(br.readLine());
		String str = br.readLine();
		s = 0;
		for(i=0;i<sz-3;i++) {
			if(str.charAt(i)=='p'&&str.charAt(i+1)=='P'&&str.charAt(i+2)=='A'&&str.charAt(i+3)=='p') {
				s++;
				i+=3;
			}
		}
		System.out.println(s);
	}
}
