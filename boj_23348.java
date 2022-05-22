import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String args[]) throws IOException {
        int[] arrScore = InputData();
        int iAnswer = Solve(arrScore);
        System.out.println(iAnswer);
    }

    private static int[] InputData() throws IOException {
        int[] arrScore = new int[3];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 3; ++i) {
            arrScore[i] = Integer.parseInt(st.nextToken());
        }
        return arrScore;
    }

    private static int Solve(int[] _arrNumber) throws IOException {
        int iN = Integer.parseInt(br.readLine());
        int iMaxScore = 0;
        for (int i = 0; i < iN; ++i) {
            int iScore = 0;
            for (int j = 0; j < 3; ++j) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int iA = Integer.parseInt(st.nextToken());
                int iB = Integer.parseInt(st.nextToken());
                int iC = Integer.parseInt(st.nextToken());
                iScore += iA * _arrNumber[0] + iB * _arrNumber[1] + iC * _arrNumber[2];
            }
            iMaxScore = Math.max(iMaxScore, iScore);
        }
        return iMaxScore;
    }
}
