import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,x,i,ans;
		ans = 0;
		boolean[] chk = new boolean[2000001];
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(n-->0) chk[Integer.parseInt(st.nextToken())] = true;
		x = Integer.parseInt(br.readLine());
		for(i=1;i<=x;i++) if(chk[i]&&chk[x-i]) ans++;
		System.out.println(ans/2);
	}
}
