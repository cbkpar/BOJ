import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] arr = new int[4][2];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        double mx = Math.pow(arr[1][0] - arr[0][0], 2) + Math.pow(arr[1][1] - arr[0][1], 2);
        mx = Math.max(mx, Math.pow(arr[3][0] - arr[2][0], 2) + Math.pow(arr[3][1] - arr[2][1], 2));
        System.out.println(Math.sqrt(mx));
    }
}
