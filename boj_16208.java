import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int n;
    	long ans,a,b;
    	PriorityQueue<Long> q = new PriorityQueue<>();
    	n = Integer.parseInt(br.readLine());
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	while(n-->0) q.add(Long.parseLong(st.nextToken()));
    	ans = 0;
    	while(q.size()>=2) {
    		a = q.poll();
    		b = q.poll();
    		ans += a*b;
    		q.add((a+b));
    	}
    	System.out.println(ans);
	}
}
