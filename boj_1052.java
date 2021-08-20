import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,k,cnt;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		if(n<=k) {
			System.out.println("0");
		}else {
			cnt = 0;
			while(Integer.bitCount(n)>k) {
				cnt += n&-n;
				n += n&-n;
			}
			System.out.println(cnt);
		}
	}
}
