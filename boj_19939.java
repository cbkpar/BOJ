import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int t = n - (k * (k + 1)) / 2;
        if (t < 0) {
            System.out.println("-1");
        } else if (t % k == 0) {
            System.out.println(k - 1);
        } else {
            System.out.println(k);
        }
    }
}
