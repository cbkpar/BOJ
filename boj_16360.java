import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n;
		char c;
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			String str = br.readLine();
			if(str.length()>=2) {
				if(str.substring(str.length()-2).equals("ne")){
					sb.append(str.substring(0, str.length()-2)+"anes\n");
					continue;
				}
			}
			sb.append(str.substring(0, str.length()-1));
			c = str.charAt(str.length()-1);
			if(c=='a') {
				sb.append("as\n");
			}else if(c=='i'||c=='y') {
				sb.append("ios\n");
			}else if(c=='l') {
				sb.append("les\n");
			}else if(c=='n') {
				sb.append("anes\n");
			}else if(c=='o') {
				sb.append("os\n");
			}else if(c=='r') {
				sb.append("res\n");
			}else if(c=='t') {
				sb.append("tas\n");
			}else if(c=='u') {
				sb.append("us\n");
			}else if(c=='v') {
				sb.append("ves\n");
			}else if(c=='w') {
				sb.append("was\n");
			}else {
				sb.append(c+"us\n");
			}
		}
		System.out.println(sb);
	}
}
