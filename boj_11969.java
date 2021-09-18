import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,q,t,i,s,e;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		q = Integer.parseInt(st.nextToken());
		int[][] arr = new int[n+1][3];
		for(i=1;i<=n;i++) {
			t = Integer.parseInt(br.readLine())-1;
			arr[i][0] = arr[i-1][0]; 
			arr[i][1] = arr[i-1][1]; 
			arr[i][2] = arr[i-1][2]; 
			arr[i][t]++;
		}
		while(q-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken())-1;
			e = Integer.parseInt(st.nextToken());
			sb.append((arr[e][0]-arr[s][0])+" "+(arr[e][1]-arr[s][1])+" "+(arr[e][2]-arr[s][2])+"\n");
		}
		System.out.println(sb);
	}
}
