import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int s;
		String str;
		str = br.readLine();
		s = 0;
		while(true) {
			str = br.readLine();
			if(str.equals("고무오리 디버깅 끝")) break;
			if(str.equals("문제")) s++;
			if(str.equals("고무오리")) s = (s==0?2:s-1);
		}
		if(s!=0) {
			System.out.println("힝구");
		}else {
			System.out.println("고무오리야 사랑해");
		}
	}
}
