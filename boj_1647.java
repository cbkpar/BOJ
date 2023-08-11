import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static int v,e,s;
	static PriorityQueue<Edge> pq = new PriorityQueue<>();
	static int[] par;
	
    public static void main(String args[]) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int i,x,y,z;
  		StringTokenizer st = new StringTokenizer(br.readLine());
    	v = Integer.parseInt(st.nextToken());
    	e = Integer.parseInt(st.nextToken());
    	for(i=0;i<e;i++) {
    		st = new StringTokenizer(br.readLine());
    		x = Integer.parseInt(st.nextToken())-1;
    		y = Integer.parseInt(st.nextToken())-1;
    		z = Integer.parseInt(st.nextToken());
    		pq.offer(new Edge(x,y,z));
    	}
    	s = 0;
    	par = new int[v];
    	for(i=0;i<v;i++) par[i]=i;
    	kruskal();
        if(v <= 2) s = 0;
    	System.out.println(s);
    }
    
    static void kruskal() {
    	int cnt=0;
    	for(int i=0;i<e;i++) {
    		int a = find(pq.peek().s1);
    		int b = find(pq.peek().s2);
    		if(a==b) {
    			pq.poll();
    			continue;
    		}
    		union(a,b);
    		s+=pq.peek().w;
    		pq.poll();
    		cnt++;
    		if(cnt==v-2) break;
    	}
    }
    
    static int find(int p) {
    	if(p==par[p]) return p;
    	return par[p]=find(par[p]);
    }
    
    static void union(int p, int q) {
    	p = find(p);
    	q = find(q);
    	if(p<q) {
    		par[q]=p;
    	}else {
    		par[p]=q;
    	}
    }
    
    static class Edge implements Comparable<Edge> {
    	int s1;
    	int s2;
    	int w;
    	
    	public Edge(int s1, int s2, int w) {
    		this.s1 = s1;
    		this.s2 = s2;
    		this.w = w;
    	}
    	@Override
    	public int compareTo(Edge o) {
    	    return Integer.compare(this.w, o.w);
    	}
    }
}
