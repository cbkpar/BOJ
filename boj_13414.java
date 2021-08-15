import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int k,l,i,cnt;
		StringTokenizer st = new StringTokenizer(br.readLine());
		k = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		HashMap<String,Integer> map = new HashMap<String,Integer>();
		HashSet<Integer> set = new HashSet<Integer>();
		Queue<String> name = new LinkedList<>();
		for(i=0;i<l;i++) {
			String str = br.readLine();
			name.add(str);
			if(map.containsKey(str)) {
				set.add(map.get(str));
			}
			map.put(str,i);
		}
		cnt = 0;
		for(i=0;i<l;i++) {
			if(name.isEmpty()||cnt==k) break;
			if(set.contains(i)) {
				name.poll();
				continue;
			}
			cnt++;
			sb.append(name.poll()+"\n");
		}
		System.out.println(sb);
	}
}
