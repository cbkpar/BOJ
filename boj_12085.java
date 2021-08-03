import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t,n,i,j,c;
		t = Integer.parseInt(br.readLine());
		for(i=1;i<=t;i++) {
			n = Integer.parseInt(br.readLine());
			ArrayList<String> arr1 = new ArrayList<String>();
			ArrayList<String> arr2 = new ArrayList<String>();
			for(j=0;j<n;j++) {
				arr1.add(br.readLine());
				arr2.add(arr1.get(j));
			}
			Collections.sort(arr2);
			c = 0;
			for(j=0;j<n;j++) {
				if(arr1.get(0).equals(arr2.get(0))) {
					arr1.remove(0);
					arr2.remove(0);
				}else {
					arr1.remove(arr2.get(0));
					arr2.remove(0);
					c++;
				}
			}
			sb.append("Case #"+i+": "+c+"\n");
		}
		System.out.println(sb);
	}
}
