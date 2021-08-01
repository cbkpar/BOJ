import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static int n,m,sum;
	static PriorityQueue<node> pq = new PriorityQueue<>();
	static int[] par;
	
    public static void main(String args[]) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int i,a,b,c;
    	n = Integer.parseInt(br.readLine());
    	m = Integer.parseInt(br.readLine());
    	for(i=0;i<m;i++) {
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		a = Integer.parseInt(st.nextToken())-1;
    		b = Integer.parseInt(st.nextToken())-1;
    		c = Integer.parseInt(st.nextToken());
    		pq.offer(new node(a,b,c));
    	}
    	sum = 0;
    	par = new int[n];
    	for(i=0;i<n;i++) par[i]=i;
    	kruskal();
    	System.out.println(sum);
    }
    
    static void kruskal() {
    	int cnt=0;
    	for(int i=0;i<m;i++) {
    		int a = find(pq.peek().s);
    		int b = find(pq.peek().e);
    		if(a==b) {
    			pq.poll();
    			continue;
    		}
    		union(a,b);
    		sum+=pq.peek().w;
    		pq.poll();
    		cnt++;
    		if(cnt==n-1) break;
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
    
    static class node implements Comparable<node> {
    	int s;
    	int e;
    	int w;
    	
    	public node(int s, int e, int w) {
    		this.s = s;
    		this.e = e;
    		this.w = w;
    	}
    	@Override
    	public int compareTo(node o) {
    	    return Integer.compare(this.w, o.w);
    	}
    }
}
