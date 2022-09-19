import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str;
        while ((str = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(str);
            double[][] arrPos = new double[4][2];
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 2; ++j) {
                    arrPos[i][j] = Double.parseDouble(st.nextToken());
                }
            }
            for (int i = 0; i < 4; ++i) {
                for (int j = i + 1; j < 4; ++j) {
                    if (arrPos[i][0] == arrPos[j][0] && arrPos[i][1] == arrPos[j][1]) {
                        double dx = arrPos[i][0] * -3;
                        double dy = arrPos[i][1] * -3;
                        for (int k = 0; k < 4; ++k) {
                            dx += arrPos[k][0];
                            dy += arrPos[k][1];
                        }
                        sb.append(String.format("%.3f %.3f\n", dx, dy));
                    }
                }
            }
        }
        System.out.println(sb);
    }
}
