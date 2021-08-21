import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n,m,i,sz,cnt,t;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		Queue<Integer> q = new LinkedList<>();
		map.put(n,0);
		q.add(n);
		cnt = 1;
		while(!q.isEmpty()) {
			sz = q.size();
			for(i=0;i<sz;i++) {
				t = q.poll();
				if(t==m) {
					Stack<Integer> stack = new Stack<>(); 
					sb.append((cnt-1)+"\n");
					while(true) {
						if(cnt==0) break;
						cnt--;
						stack.add(t);
						if(map.containsKey(t-1)) if(map.get(t-1)==cnt-1){
							t--;
							continue;
						}
						if(map.containsKey(t+1)) if(map.get(t+1)==cnt-1){
							t++;
							continue;
						}
						if(map.containsKey(t/2)) if(map.get(t/2)==cnt-1){
							t /= 2;
							continue;
						}
					}
					while(!stack.isEmpty()) sb.append(stack.pop()+" ");
					System.out.println(sb);
					return;
				}
				if(t-1>=0&&!map.containsKey(t-1)) {
					map.put(t-1,cnt);
					q.add(t-1);
				}
				if(t+1<=100000&&!map.containsKey(t+1)) {
					map.put(t+1,cnt);
					q.add(t+1);
				}
				if(t*2<=100000&&!map.containsKey(t*2)) {
					map.put(t*2,cnt);
					q.add(t*2);
				}
			}
			cnt++;
		}
	}
}
