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
		int n,k,i,j,w,l,r,m,t,sz,qsz,p;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int[][] pos = new int[n+2][2];
		for(i=1;i<n+1;i++) {
			st = new StringTokenizer(br.readLine());
			pos[i][0] = Integer.parseInt(st.nextToken());
			pos[i][1] = Integer.parseInt(st.nextToken());
		}
		pos[n+1][0] = pos[n+1][1] = 10000;
		ArrayList<node>[] arr = new ArrayList[n+2];
		for(i=0;i<=n+1;i++) arr[i] = new ArrayList<node>();
		for(i=0;i<n+1;i++) for(j=i+1;j<n+2;j++) {
			w = (int)Math.ceil(Math.sqrt(Math.pow(pos[i][0]-pos[j][0],2)+Math.pow(pos[i][1]-pos[j][1],2))/10);
			arr[i].add(new node(j,w));
			arr[j].add(new node(i,w));
		}
		l = 0;
		r = 1415;
		while(l<r) {
			m = (l+r)/2;
			boolean[] visited = new boolean[n+2];
	        Queue<Integer> q = new LinkedList<>();
	        q.add(0);
	        visited[0] = true;
	        for(i=0;i<=k;i++) {
	        	if(visited[n+1]) break;
	        	sz = q.size();
	        	for(j=0;j<sz;j++) {
	        		t = q.poll();
	        		qsz = arr[t].size();
	        		for(p=0;p<qsz;p++) {
	        			if(arr[t].get(p).w<=m&&!visited[arr[t].get(p).e]) {
	        				visited[arr[t].get(p).e] = true;
	        				q.add(arr[t].get(p).e);
	        			}
	        		}
	        	}
	        }
	        if(visited[n+1]) {
	        	r = m;
	        }else {
	        	l = m+1;
	        }
		}
		System.out.println(l);
	}
	
	public static class node {
		int e;
		int w;
		
		public node(int e, int w) {
			this.e = e;
			this.w = w;
		}
	}
}
