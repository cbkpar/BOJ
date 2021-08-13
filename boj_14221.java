import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static ArrayList<node>[] arr;
	static int[] dist;
	static int[] store;
	static int[] house;
	static boolean[] chk;
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i,j,s,e,k,p,q,mx,num;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new ArrayList[n+1];
		for(i=1;i<=n;i++) arr[i] = new ArrayList<node>();
		while(m-->0) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			arr[s].add(new node(e, k));
			arr[e].add(new node(s, k));
		}
		st = new StringTokenizer(br.readLine());
		p = Integer.parseInt(st.nextToken());
		q = Integer.parseInt(st.nextToken());
		house = new int[p];
		store = new int[q];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<p;i++) {
			house[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(i=0;i<q;i++) {
			store[i] = Integer.parseInt(st.nextToken());
		}
		num = 0;
		mx = Integer.MAX_VALUE;
		Arrays.sort(house);
		for(i=0;i<p;i++) {
			dist = new int[n+1];
			chk = new boolean[n+1];
			dijkstra(house[i]);
			for(j=0;j<q;j++) {
				if(dist[store[j]]<mx) {
					mx = dist[store[j]];
					num = house[i];
				}
			}
		}
		System.out.println(num);
	}
	
	public static void dijkstra(int start){
	    PriorityQueue<node> priorityQueue = new PriorityQueue<>();
	    Arrays.fill(dist,Integer.MAX_VALUE);
	    priorityQueue.add(new node(start,0));
	    dist[start] = 0;
	    while (!priorityQueue.isEmpty()) {
	        node N = priorityQueue.poll();
	        int e = N.e;
	        if(chk[e]) {
	           continue;
	        }else {
	           chk[N.e] = true;
	        }
	        for (node next : arr[e]) {
	            if (dist[next.e] >= dist[e] + next.w) {
	                dist[next.e] = dist[e] + next.w;
	                priorityQueue.add(new node(next.e,dist[next.e]));
	            }
	        }
	    }
	}

	
	public static class node implements Comparable<node>{
		int e;
		int w;
		
		public node(int e, int w) {
			this.e = e;
			this.w = w;
		}
		
		@Override
		public int compareTo(node o) {
			return Integer.compare(this.w, o.w);
		}
	}
}
