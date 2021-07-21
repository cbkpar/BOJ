import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n,k,m,t;
		int[] cnt = new int[100001];
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		m = 0;
		Deque<Integer> q = new ArrayDeque<>();
		st = new StringTokenizer(br.readLine());
		while(n-->0) {
			t = Integer.parseInt(st.nextToken());
			cnt[t]++;
			q.add(t);
			while(cnt[t]>k) cnt[q.pop()]--;
			m = Math.max(m, q.size());
		}
		System.out.println(m);
	}
}
