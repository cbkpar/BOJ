import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,i;
		n = Integer.parseInt(br.readLine());
		int[][] map = new int[n+1][3];
		int[][] mx = new int[n+1][3];
		int[][] mi = new int[n+1][3];
		for(i=1;i<=n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			map[i][0] = Integer.parseInt(st.nextToken());
			map[i][1] = Integer.parseInt(st.nextToken());
			map[i][2] = Integer.parseInt(st.nextToken());
			mx[i][0] = map[i][0] + Math.max(mx[i-1][0], mx[i-1][1]);
			mx[i][1] = map[i][1] + Math.max(mx[i-1][0], Math.max(mx[i-1][1], mx[i-1][2]));
			mx[i][2] = map[i][2] + Math.max(mx[i-1][1], mx[i-1][2]);
			mi[i][0] = map[i][0] + Math.min(mi[i-1][0], mi[i-1][1]);
			mi[i][1] = map[i][1] + Math.min(mi[i-1][0], Math.min(mi[i-1][1], mi[i-1][2]));
			mi[i][2] = map[i][2] + Math.min(mi[i-1][1], mi[i-1][2]);
		}
		System.out.println(Math.max(mx[n][0], Math.max(mx[n][1], mx[n][2]))+" "+Math.min(mi[n][0], Math.min(mi[n][1], mi[n][2])));
	}
}
