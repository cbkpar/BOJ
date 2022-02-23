import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		boolean[] visited = new boolean[n];
		boolean[] used = new boolean[26];
		char[] arr = new char[n];
		int pos = 0;
		while (k-- > 0) {
			st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			char ch = st.nextToken().charAt(0);
			pos = (pos + num) % n;
			if ((visited[pos] && ch != arr[pos]) || (used[ch - 'A'] && arr[pos] != ch)) {
				System.out.println("!");
				return;
			}
			visited[pos] = true;
			arr[pos] = ch;
			used[ch - 'A'] = true;
		}
		for (int i = 0; i < n; i++) {
			sb.append(visited[pos] ? arr[pos] : "?");
			pos = (pos + n - 1) % n;
		}
		System.out.println(sb);
	}
}
