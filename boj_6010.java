import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	int n,q,i,t,left,right,mid;
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	q = Integer.parseInt(st.nextToken());
    	int[] arr = new int[n+1];
    	for(i=1;i<=n;i++) arr[i] += arr[i-1] + Integer.parseInt(br.readLine());
    	while(q-->0) {
    		t = Integer.parseInt(br.readLine());
    		left = 0;
    		right = n;
    		while(left<right) {
    			mid = (left+right)/2;
    			if(arr[mid]>t) {
    				right = mid;
    			}else {
    				left = mid+1;
    			}
    		}
    		sb.append((right)+"\n");
    	}
    	System.out.println(sb);
    }
}
