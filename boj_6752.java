import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t,c,i,cnt;
		t = Integer.parseInt(br.readLine());
		c = Integer.parseInt(br.readLine());
		int[] arr = new int[c];
		for(i=0;i<c;i++) arr[i] = Integer.parseInt(br.readLine());
		Arrays.sort(arr);
		cnt = 0;
		for(i=0;i<c;i++) {
			if(t>=arr[i]) {
				t -= arr[i];
				cnt++;
			}else {
				break;
			}
		}
		System.out.println(cnt);
	}
}
