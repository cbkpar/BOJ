import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int sum,i;
		while(true) {
			String str = br.readLine();
			if(str.equals("#")) break;
			sum = 0;
			for(i=0;i<str.length();i++) {
				if(str.charAt(i)>='A'&&str.charAt(i)<='Z') sum += (i+1)*(str.charAt(i)-'A'+1);
			}
			sb.append(sum+"\n");
		}
		System.out.println(sb);
	}
}
