import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	int i,j,s,e;
    	String str;
    	int[] dp = new int[10000001];
    	Arrays.fill(dp,1);
		dp[0] = dp[1] = 0;
		for(i=2;i*i<=10000000;i++) if(dp[i]==1) for(j=i*i;j<=10000000;j+=i) dp[j] = 0;
		for(i=2;i<=10000000;i++) dp[i] += dp[i-1];
    	while((str=br.readLine())!=null) {
    		StringTokenizer st = new StringTokenizer(str);
    		if(st.hasMoreTokens()) {
    			s = Integer.parseInt(st.nextToken())-1;
    			e = Integer.parseInt(st.nextToken());
    			sb.append((dp[e]-dp[s])+"\n");
    		}else {
    			sb.append("\n");
    		}
    	}
    	System.out.println(sb);
    }
}
