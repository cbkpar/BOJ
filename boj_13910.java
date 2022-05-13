import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String args[]) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        int[] arrWokMixSize = getWok(iM);
        System.out.println(Solve(iN, arrWokMixSize));
    }

    public static int[] getWok(int _iM) throws IOException {
        int[] arrWokSize = new int[_iM];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < _iM; ++i) {
            arrWokSize[i] = Integer.parseInt(st.nextToken());
        }
        HashSet<Integer> setWokMixSize = new HashSet<>();
        for (int i = 0; i < _iM; ++i) {
            for (int j = 0; j < _iM; ++j) {
                if (i == j) {
                    setWokMixSize.add(arrWokSize[i]);
                } else {
                    setWokMixSize.add(arrWokSize[i] + arrWokSize[j]);
                }
            }
        }
        int iSetSize = setWokMixSize.size();
        int[] arrWokMixSize = new int[iSetSize];
        int iIndex = 0;
        for (int iMixSize : setWokMixSize) {
            arrWokMixSize[iIndex++] = iMixSize;
        }
        return arrWokMixSize;
    }

    public static int Solve(int _iN, int[] _arrWokMixSize) {
        boolean[] bVisited = new boolean[_iN + 1];
        Queue<Integer> qFoodSize = new LinkedList<>();
        qFoodSize.add(0);
        bVisited[0] = true;
        int iWoklen = _arrWokMixSize.length;
        int iCount = 0;
        while (!qFoodSize.isEmpty()) {
            int iSize = qFoodSize.size();
            while (iSize-- > 0) {
                int iNow = qFoodSize.poll();
                if (iNow == _iN) return iCount;
                for (int i = 0; i < iWoklen; ++i) {
                    int iNext = iNow + _arrWokMixSize[i];
                    if (iNext > _iN || bVisited[iNext]) continue;
                    bVisited[iNext] = true;
                    qFoodSize.add(iNext);
                }
            }
            ++iCount;
        }
        return -1;
    }
}
