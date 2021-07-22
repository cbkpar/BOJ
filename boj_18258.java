import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n;
		Deque<Integer> q = new ArrayDeque<>();
		n = Integer.parseInt(br.readLine());
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			if(str.equals("push")) {
				q.add(Integer.parseInt(st.nextToken()));
			}else if(str.equals("pop")) {
				if(q.isEmpty()) {
					sb.append("-1\n");
				}else {
					sb.append(q.poll()+"\n");
				}
			}else if(str.equals("size")) {
				sb.append(q.size()+"\n");
			}else if(str.equals("empty")){
				if(q.isEmpty()) {
					sb.append("1\n");
				}else {
					sb.append("0\n");
				}
			}else if(str.equals("front")) {
				if(q.isEmpty()) {
					sb.append("-1\n");
				}else {
					sb.append(q.getFirst()+"\n");
				}
			}else {
				if(q.isEmpty()) {
					sb.append("-1\n");
				}else {
					sb.append(q.getLast()+"\n");
				}
			}
		}
		System.out.println(sb);
	}
}
