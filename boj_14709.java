import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,a,b;
		n = Integer.parseInt(br.readLine());
		boolean[][] map = new boolean[6][6];
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			if(a==2||a==5||b==2||b==5) {
				System.out.println("Woof-meow-tweet-squeek");
				return;
			}
			map[a][b] = map[b][a] = true;
		}
		if(map[1][3]&&map[1][4]&&map[3][4]) {
			System.out.println("Wa-pa-pa-pa-pa-pa-pow!");
		}else {
			System.out.println("Woof-meow-tweet-squeek");
		}
	}
}
