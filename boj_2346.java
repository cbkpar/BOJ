import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,i,t,k;
		n = Integer.parseInt(br.readLine());
		int[] arr = new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(i=1;i<=n;i++) arr[i] = Integer.parseInt(st.nextToken());
		LinkedList<Integer> list = new LinkedList<>();
		for(i=1;i<=n;i++) list.add(i);
		t = k = 0;
		while(true) {
			t = arr[list.get(k)];
			if(t>0) t--;
			sb.append(list.get(k)+" ");
			list.remove(k);
			if(list.isEmpty()) break;
			k = (k+t+1001*list.size())%list.size();
		}
		System.out.println(sb);
	}
}
