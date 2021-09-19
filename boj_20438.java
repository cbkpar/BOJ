import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	int n,k,q,m,t,i,s,e;
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	k = Integer.parseInt(st.nextToken());
    	q = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	boolean[] chk = new boolean[n+3];
    	int[] dp = new int[n+3];
    	st = new StringTokenizer(br.readLine());
    	while(k-->0) {
    		chk[Integer.parseInt(st.nextToken())] = true;
    	}
    	st = new StringTokenizer(br.readLine());
    	while(q-->0) {
    		t = Integer.parseInt(st.nextToken());
    		if(chk[t]) continue;
    		for(i=t;i<=n+2;i+=t) if(!chk[i]) dp[i] = 1;
    	}
    	for(i=3;i<=n+2;i++) dp[i] += dp[i-1];
    	while(m-->0) {
    		st = new StringTokenizer(br.readLine());
    		s = Integer.parseInt(st.nextToken());
    		e = Integer.parseInt(st.nextToken());
    		sb.append((e-s-dp[e]+dp[s-1]+1)+"\n");
    	}
    	System.out.println(sb);
    }
}
