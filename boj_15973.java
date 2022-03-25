import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x1 = Integer.parseInt(st.nextToken());
        int y1 = Integer.parseInt(st.nextToken());
        int x2 = Integer.parseInt(st.nextToken());
        int y2 = Integer.parseInt(st.nextToken());
        box A = new box(x1, y1, x2, y2);
        st = new StringTokenizer(br.readLine());
        x1 = Integer.parseInt(st.nextToken());
        y1 = Integer.parseInt(st.nextToken());
        x2 = Integer.parseInt(st.nextToken());
        y2 = Integer.parseInt(st.nextToken());
        box B = new box(x1, y1, x2, y2);
        x1 = Math.max(A.x1, B.x1);
        y1 = Math.max(A.y1, B.y1);
        x2 = Math.min(A.x2, B.x2);
        y2 = Math.min(A.y2, B.y2);
        System.out.println(verify(x1, y1, x2, y2));
    }

    private static String verify(int x1, int y1, int x2, int y2) {
        if (x2 < x1 || y2 < y1) {
            return "NULL";
        }
        if (x1 == x2) {
            if (y1 == y2) return "POINT";
            return "LINE";
        }
        if (y1 == y2) return "LINE";
        return "FACE";
    }
}

class box {
    int x1, y1, x2, y2;

    public box(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }
}
