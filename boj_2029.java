import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] map = new String[10];
        int A = 24;
        int B = 0;
        for (int i = 0; i < 10; i++) map[i] = br.readLine();
        int[][] rows = new int[4][3];
        int[][] cols = new int[3][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (map[i * 3].charAt(j * 3 + 1) == '-') {
                    rows[i][j] = 1;
                    A--;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (map[i * 3 + 1].charAt(j * 3) == '|') {
                    cols[i][j] = 1;
                    A--;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int sum = 0;
                sum += rows[i][j];
                sum += rows[i + 1][j];
                sum += cols[i][j];
                sum += cols[i][j + 1];
                if (sum == 4) B++;
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int sum = 0;
                sum += rows[i][j];
                sum += rows[i][j + 1];
                sum += rows[i + 2][j];
                sum += rows[i + 2][j + 1];
                sum += cols[i][j];
                sum += cols[i + 1][j];
                sum += cols[i][j + 2];
                sum += cols[i + 1][j + 2];
                if (sum == 8) B++;
            }
        }
        int sum = 0;
        sum += rows[0][0];
        sum += rows[0][1];
        sum += rows[0][2];
        sum += rows[3][0];
        sum += rows[3][1];
        sum += rows[3][2];
        sum += cols[0][0];
        sum += cols[1][0];
        sum += cols[2][0];
        sum += cols[0][3];
        sum += cols[1][3];
        sum += cols[2][3];
        if (sum == 12) B++;
        System.out.println(A + " " + B);
    }
}
