import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int G = Integer.parseInt(st.nextToken());
        HashMap<String, Integer> map = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < A; i++) map.put(st.nextToken(), 1);
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < B; i++) map.put(st.nextToken(), -1);
        int sum = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < G; i++) sum += map.get(st.nextToken());
        if (sum > 0) {
            System.out.println("A");
        } else if (sum < 0) {
            System.out.println("B");
        } else {
            System.out.println("TIE");
        }
    }
}
