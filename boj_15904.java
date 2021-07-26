import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sz,i,t;
		int[] ans = {0,1,2,1};
		String str = br.readLine();
		sz = str.length();
		ArrayList<Integer> arr = new ArrayList<Integer>();
		for(i=0;i<sz;i++) {
			if(str.charAt(i)=='U') arr.add(0);
			if(str.charAt(i)=='C') arr.add(1);
			if(str.charAt(i)=='P') arr.add(2);
		}
		sz = arr.size();
		t = 0;
		for(i=0;i<sz;i++) {
			if(ans[t]==arr.get(i)) t++;
			if(t==4) {
				System.out.println("I love UCPC");
				return;
			}
		}
		System.out.println("I hate UCPC");
	}
}
