import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        st.nextToken();
        String pre = st.nextToken();
        int limit = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(br.readLine());
        ArrayList<String> arr = new ArrayList<>();
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            if (!pre.contains(st.nextToken())) continue;
            if (Integer.parseInt(st.nextToken()) > limit) continue;
            arr.add(name);
        }
        Collections.sort(arr);
        if (arr.isEmpty()) {
            System.out.println("No one yet");
        } else {
            StringBuilder sb = new StringBuilder();
            for (String str : arr) sb.append(str + "\n");
            System.out.println(sb);
        }
    }
}
