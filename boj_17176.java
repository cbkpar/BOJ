import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		char[] arr = new char[53];
		int[] cnt = new int[53];
		arr[0] = ' ';
		for(i=1;i<=26;i++) arr[i] = (char)(i+'A'-1);
		for(i=27;i<=52;i++) arr[i] = (char)(i+'a'-27);
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) cnt[Integer.parseInt(st.nextToken())]++;
		String str = br.readLine();
		for(i=0;i<n;i++) {
			if(str.charAt(i)==' ') {
				cnt[0]--;
			}else if(str.charAt(i)>='A'&&str.charAt(i)<='Z') {
				cnt[str.charAt(i)-'A'+1]--;
			}else {
				cnt[str.charAt(i)-'a'+27]--;
			}
		}
		for(i=0;i<53;i++) if(cnt[i]!=0) {
			System.out.println("n");
			return;
		}
		System.out.println("y");
	}
}
