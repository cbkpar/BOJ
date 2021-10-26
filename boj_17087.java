import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int g = Math.abs(Integer.parseInt(st.nextToken()) - s);
        for (int i = 1; i < n; i++) {
            int k = Math.abs(Integer.parseInt(st.nextToken()) - s);
            if (g > k) {
                g = gcd(k, g);
            } else {
                g = gcd(g, k);
            }
        }
        System.out.println(g);
    }

    private static int gcd(int a, int b) {
        if (b % a == 0) return a;
        return gcd(b % a, a);
    }
}
