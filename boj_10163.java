import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
		int n,i,j,k,a,b,c,d;
		n = Integer.parseInt(br.readLine());
		int[] cnt = new int[n+1];
		int[][] map = new int[1001][1001];
		for(i=1;i<=n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			for(j=a;j<a+c;j++) for(k=b;k<b+d;k++) map[j][k] = i;
		}
		for(i=0;i<1001;i++) for(j=0;j<1001;j++) cnt[map[i][j]]++;
		for(i=1;i<=n;i++) sb.append(cnt[i]+"\n");
		System.out.println(sb);
	}
}
