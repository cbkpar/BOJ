import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int k,sz,i;
		StringTokenizer st = new StringTokenizer(br.readLine());
		k = Integer.parseInt(st.nextToken());
		sz = Integer.parseInt(st.nextToken());
		String str = br.readLine();
		for(i=0;i<sz;i++) {
			if(str.charAt(i)>='a'&&str.charAt(i)<='z') {
				sb.append((char)(((str.charAt(i)-'a')+k)%26+'a'));
			}else if(str.charAt(i)>='A'&&str.charAt(i)<='Z') {
				sb.append((char)(((str.charAt(i)-'A')+k)%26+'A'));
			}else {
				sb.append(str.charAt(i));
			}
		}
		System.out.println(sb);
	}
}
