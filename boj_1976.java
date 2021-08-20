import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,t;
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		int[][] arr = new int[n+1][n+1];
		for(i=1;i<=n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(j=1;j<=n;j++) arr[i][j] = Integer.parseInt(st.nextToken());
		}
		StringTokenizer st = new StringTokenizer(br.readLine());
		boolean[] visited = new boolean[n+1];
		t = Integer.parseInt(st.nextToken());
		Queue<Integer> q = new LinkedList<>();
		q.add(t);
		visited[t] = true;
		boolean chk = true;
		while(!q.isEmpty()) {
			t = q.poll();
			for(i=1;i<=n;i++) {
				if(arr[t][i]==1&&!visited[i]) {
					visited[i] = true;
					q.add(i);
				}
			}
		}
		for(i=1;i<m;i++) if(!visited[Integer.parseInt(st.nextToken())]) chk = false;
		System.out.println(chk?"YES":"NO");
	}
}
