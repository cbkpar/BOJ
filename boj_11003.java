import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        ArrayDeque<number> dq = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            while (!dq.isEmpty() && dq.getFirst().idx <= i - l) dq.pollFirst();
            while (!dq.isEmpty() && dq.getLast().num >= num) dq.pollLast();
            dq.add(new number(i, num));
            sb.append(dq.peekFirst().num + " ");
        }
        System.out.println(sb);
    }
}

class number implements Comparable<number> {
    int idx;
    int num;

    public number(int idx, int num) {
        this.idx = idx;
        this.num = num;
    }

    @Override
    public int compareTo(number o) {
        return Integer.compare(this.num, o.num);
    }
}
