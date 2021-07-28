import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int s,i;
		boolean chk = false;
		s = 0;
		String str = br.readLine();
		for(i=0;i<13;i++) {
			if(str.charAt(i)=='*') {
				if(i%2==0) chk = true;
				continue;
			}
			if(i%2==0) {
				s += str.charAt(i)-'0';
			}else {
				s += (str.charAt(i)-'0')*3;
			}
		}
		s %= 10;
		if(chk) {
			System.out.println((10-s)%10);
		}else {
			System.out.println((10-(((3-s%3)%3)*10+s)/3)%10);
		}
	}
}
