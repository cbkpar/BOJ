import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static int[][] prev;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        prev = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) prev[i][j] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        while (r-- > 0) {
            int num = Integer.parseInt(st.nextToken());
            command(num, prev);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) sb.append(prev[i][j] + " ");
            sb.append(prev[i][m - 1] + "\n");
        }
        System.out.println(sb);
    }

    private static void command(int r, int[][] arr) {
        if (r == 1) udswtich(arr);
        if (r == 2) lrswtich(arr);
        if (r == 3) rotatel(arr);
        if (r == 4) rotater(arr);
        if (r == 5) rotatel2(arr);
        if (r == 6) rotater2(arr);
    }

    private static void udswtich(int[][] arr) {
        int[][] next = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                next[n - i - 1][j] = arr[i][j];
            }
        }
        prev = next;
    }

    private static void lrswtich(int[][] arr) {
        int[][] next = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                next[i][m - j - 1] = arr[i][j];
            }
        }
        prev = next;
    }

    private static void rotatel(int[][] arr) {
        int tmp = n;
        n = m;
        m = tmp;
        int[][] next = new int[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                next[j][m - i - 1] = arr[i][j];
            }
        }
        prev = next;
    }

    private static void rotater(int[][] arr) {
        int tmp = n;
        n = m;
        m = tmp;
        int[][] next = new int[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                next[n - j - 1][i] = arr[i][j];
            }
        }
        prev = next;
    }

    private static void rotatel2(int[][] arr) {
        int dy = n / 2;
        int dx = m / 2;
        int[][] next = new int[n][m];
        for (int i = 0; i < dy; i++) {
            for (int j = 0; j < dx; j++) {
                next[i][j + dx] = arr[i][j];
            }
        }
        for (int i = 0; i < dy; i++) {
            for (int j = dx; j < m; j++) {
                next[i + dy][j] = arr[i][j];
            }
        }
        for (int i = dy; i < n; i++) {
            for (int j = dx; j < m; j++) {
                next[i][j - dx] = arr[i][j];
            }
        }
        for (int i = dy; i < n; i++) {
            for (int j = 0; j < dx; j++) {
                next[i - dy][j] = arr[i][j];
            }
        }
        prev = next;
    }

    private static void rotater2(int[][] arr) {
        int dy = n / 2;
        int dx = m / 2;
        int[][] next = new int[n][m];
        for (int i = 0; i < dy; i++) {
            for (int j = 0; j < dx; j++) {
                next[i + dy][j] = arr[i][j];
            }
        }
        for (int i = 0; i < dy; i++) {
            for (int j = dx; j < m; j++) {
                next[i][j - dx] = arr[i][j];
            }
        }
        for (int i = dy; i < n; i++) {
            for (int j = dx; j < m; j++) {
                next[i - dy][j] = arr[i][j];
            }
        }
        for (int i = dy; i < n; i++) {
            for (int j = 0; j < dx; j++) {
                next[i][j + dx] = arr[i][j];
            }
        }
        prev = next;
    }
}
