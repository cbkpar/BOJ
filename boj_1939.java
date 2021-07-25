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
		int n,m,i,s,e,w,left,right,mid,t,sz;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		ArrayList<node>[] arr = new ArrayList[n+1];
		for(i=1;i<=n;i++) arr[i] = new ArrayList<node>();
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			arr[s].add(new node(e,w));
			arr[e].add(new node(s,w));
		}
		st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		left = 0;
		right = 1000000001;
		while(left<right) {
			mid = (left+right)/2;
			boolean[] visited = new boolean[100001];
	        Queue<Integer> q = new LinkedList<>();
	        q.add(s);
	        visited[s] = true;
	        while(!q.isEmpty()) {
	        	t = q.poll();
	        	sz = arr[t].size();
	        	for(i=0;i<sz;i++) {
	        		if(arr[t].get(i).w>=mid&&!visited[arr[t].get(i).e]) {
	        			visited[arr[t].get(i).e] = true;
	        			q.add(arr[t].get(i).e);
	        		}
	        	}
	        }
	        if(visited[e]) {
	        	left = mid+1;
	        }else {
	        	right = mid;
	        }
		}
		System.out.println(left-1);
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
