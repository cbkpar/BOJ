import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> arrNumber = new ArrayList<>();
        int iN = Integer.parseInt(br.readLine());
        for (int i = 1; i <= iN; ++i) {
            arrNumber.add(i);
        }
        long lSelect = 0;
        for (int i = 1; i < iN; ++i) {
            long lStage = i;
            lSelect = (lSelect + lStage * lStage * lStage - 1) % arrNumber.size();
            arrNumber.remove((int) lSelect);
        }
        System.out.println(arrNumber.get(0));
    }
}
