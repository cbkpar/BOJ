import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int n,m,i,s,e,ans;
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	int[] arr = new int[n+1];
    	st = new StringTokenizer(br.readLine());
    	for(i=1;i<=n;i++) arr[i] = arr[i-1]^Integer.parseInt(st.nextToken());
    	ans = 0;
    	while(m-->0) {
    		st = new StringTokenizer(br.readLine());
    		s = Integer.parseInt(st.nextToken())-1;
    		e = Integer.parseInt(st.nextToken());
    		ans = ans^(arr[e]^arr[s]);
    	}
    	System.out.println(ans);
    }
}
