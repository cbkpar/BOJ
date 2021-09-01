import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n,m,i;
        long ans;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long[] arr = new long[n+1];
        for(i=1;i<=n;i++) arr[i] = arr[i-1] + Long.parseLong(st.nextToken());
        ans = 0;
        for(i=m;i<=n;i++) ans = Math.max(ans, arr[i]-arr[i-m]);
        System.out.println(ans);
	}
}
