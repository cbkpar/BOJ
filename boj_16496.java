import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i;
		n = Integer.parseInt(br.readLine());
        ArrayList<String> arr = new ArrayList<String>();
        StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=0;i<n;i++) arr.add(st.nextToken());
		Collections.sort(arr, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return o2.concat(o1).compareTo(o1.concat(o2));
			}
		});
		boolean chk = false;
		for(i=0;i<n;i++) {
			if(arr.get(i).charAt(0)!='0') {
				chk = true;
				break;
			};
		}
		if(!chk) {
			sb.append("0");
		}else {
			for(i=0;i<n;i++) sb.append(arr.get(i));
		}
		System.out.println(sb);
	}
}
