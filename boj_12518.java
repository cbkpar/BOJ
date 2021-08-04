import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,i;
		t = Integer.parseInt(br.readLine());
		for(i=1;i<=t;i++) {
			String str = br.readLine();
			char c = str.charAt(str.length()-1);
			if(c>='A'&&c<='Z') c-='A'-'a';
			if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
				sb.append("Case #"+i+": "+str+" is ruled by a queen.\n");
			}else if(c=='y') {
				sb.append("Case #"+i+": "+str+" is ruled by nobody.\n");
			}else {
				sb.append("Case #"+i+": "+str+" is ruled by a king.\n");
			}
		}
		System.out.println(sb);
	}
}
