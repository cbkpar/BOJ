import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t,n,i,j,a,b;
		int[][] map = new int[3][3];
		for(i=0;i<3;i++) for(j=0;j<3;j++) map[i][j] = -100+i*10+j;
		t = Integer.parseInt(br.readLine());
		for(n=0;n<9;n++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken())-1;
			b = Integer.parseInt(st.nextToken())-1;
			map[a][b] = t;
			for(i=0;i<3;i++) if(map[i][0]==map[i][1]&&map[i][0]==map[i][2]) {
				System.out.println(map[i][0]);
				return;
			}
			for(i=0;i<3;i++) if(map[0][i]==map[1][i]&&map[0][i]==map[2][i]) {
				System.out.println(map[0][i]);
				return;
			}
			if(map[0][0]==map[1][1]&&map[0][0]==map[2][2]) {
				System.out.println(map[0][0]);
				return;
			}
			if(map[0][2]==map[1][1]&&map[0][2]==map[2][0]) {
				System.out.println(map[0][2]);
				return;
			}
			t = t==2?1:2;
		}
		System.out.println("0");
	}
}
