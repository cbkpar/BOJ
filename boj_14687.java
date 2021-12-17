import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        ArrayDeque<Integer> Deque = new ArrayDeque<>();
        Queue<Integer> Queue = new LinkedList<>();
        for (int i = 0; i < (n + 1) / 2; i++) {
            Deque.addLast(arr[i]);
        }
        for (int i = (n + 1) / 2; i < n; i++) {
            Queue.add(arr[i]);
        }
        while (!Deque.isEmpty()) {
            if (!Deque.isEmpty()) sb.append(Deque.pollLast() + " ");
            if (!Queue.isEmpty()) sb.append(Queue.poll() + " ");
        }
        System.out.println(sb.toString().trim());
    }
}
