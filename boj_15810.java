import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,m,i;
		long left,right,mid,tmp;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
		left = mid = 0;
		right = 1000000000001L;
		while(left<right) {
			mid = (left+right)/2;
			tmp = 0;
			for(i=0;i<n;i++) tmp += mid/arr[i];
			if(tmp<m) {
				left = mid+1; 
			}else {
				right = mid;
			}
		}
		System.out.println(right);
	}
}
