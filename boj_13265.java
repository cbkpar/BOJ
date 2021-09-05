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
		StringBuilder sb = new StringBuilder();
		int t,n,m,i,j,k,s,e,z,sz,p,qsz;
		t = Integer.parseInt(br.readLine());
		while(t-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			ArrayList<Integer>[] node = new ArrayList[n+1];
			for(i=1;i<=n;i++) node[i] = new ArrayList<Integer>();
			int[] arr = new int[n+1];
			while(m-->0) {
				st = new StringTokenizer(br.readLine());
				s = Integer.parseInt(st.nextToken());
				e = Integer.parseInt(st.nextToken());
				node[s].add(e);
				node[e].add(s);
			}
			boolean[] chk = new boolean[n+1];
			boolean ispossible = true;
			for(i=1;i<=n;i++) {
				if(!chk[i]) {
					Queue<Integer> q = new LinkedList<>();
					q.add(i);
					chk[i] = true;
					z = 0;
					while(!q.isEmpty()) {
						sz = q.size();
						for(j=0;j<sz;j++) {
							p = q.poll();
							qsz = node[p].size();
							for(k=0;k<qsz;k++) {
								if(chk[node[p].get(k)]) {
									if(arr[node[p].get(k)]==z) {
										ispossible = false;
										break;
									}
								}else {
									q.add(node[p].get(k));
									chk[node[p].get(k)] = true;
									arr[node[p].get(k)] = (z+1)%2;
								}
							}
						}
						z = (z+1)%2;
					}
				}
			}
			sb.append(ispossible?"possible\n":"impossible\n");
		}
		System.out.println(sb);
	}
}
