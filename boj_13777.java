import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,left,right,mid;
		while(true) {
			n = Integer.parseInt(br.readLine());
			if(n==0) break;
			left = 1;
			right = 50;
			while(left<=right) {
				mid = (left+right)/2;
				sb.append(mid+" ");
				if(mid==n) break;
				if(mid>n) {
					right = mid-1;
				}else {
					left = mid+1;
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
