import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int n,k,s,e,i;
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	k = Integer.parseInt(st.nextToken());
    	int[] arr = new int[n+1];
    	while(k-->0) {
    		st = new StringTokenizer(br.readLine());
    		s = Integer.parseInt(st.nextToken());
    		e = Integer.parseInt(st.nextToken());
    		arr[s]++;
    		if(e!=n) arr[e+1]--;
    	}
    	for(i=1;i<=n;i++) arr[i] += arr[i-1];
    	Arrays.sort(arr);
    	System.out.println(arr[(n+1)/2]);
    }
}
