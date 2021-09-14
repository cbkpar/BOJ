import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,a,b,mx;
		n = Integer.parseInt(br.readLine());
		int[][] map = new int[4][4];
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			map[a][b]++;
		}
		mx = map[1][2]+map[2][3]+map[3][1];
		mx = Math.max(mx, map[1][3]+map[2][1]+map[3][2]);
		System.out.println(mx);
	}
}
