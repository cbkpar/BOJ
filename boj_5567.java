import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,s,e,t,sz,p,qsz,ans;
		n = Integer.parseInt(br.readLine());
		ArrayList<Integer>[] arr = new ArrayList[n+1];
		for(i=1;i<=n;i++) arr[i] = new ArrayList<Integer>();
		boolean[] visit = new boolean[n+1];
		m = Integer.parseInt(br.readLine());
		while(m-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			arr[s].add(e);
			arr[e].add(s);
		}
		Queue<Integer> q = new LinkedList<>();
		q.add(1);
		visit[1] = true;
		t = 0;
		while(!q.isEmpty()) {
			if(t++==2) break;
			sz = q.size();
			for(i=0;i<sz;i++) {
				p = q.poll();
				qsz = arr[p].size();
				for(j=0;j<qsz;j++) {
					if(!visit[arr[p].get(j)]) {
						visit[arr[p].get(j)] = true;
						q.add(arr[p].get(j));
					}
				}
			}
		}
		ans = 0;
		for(i=2;i<=n;i++) if(visit[i]) ans++;
		System.out.println(ans);
	}
}
