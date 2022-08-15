import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        int iR = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] arrNode = new ArrayList[iN + 1];
        for (int i = 1; i <= iN; ++i) {
            arrNode[i] = new ArrayList<>();
        }
        for (int i = 0; i < iM; ++i) {
            st = new StringTokenizer(br.readLine());
            int iS = Integer.parseInt(st.nextToken());
            int iE = Integer.parseInt(st.nextToken());
            arrNode[iS].add(iE);
            arrNode[iE].add(iS);
        }
        for (int i = 1; i <= iN; ++i) {
            Collections.sort(arrNode[i], Comparator.reverseOrder());
        }
        boolean[] bVisited = new boolean[iN + 1];
        int[] arrCount = new int[iN + 1];
        bVisited[iR] = true;
        Queue<Integer> qPos = new LinkedList<>();
        qPos.add(iR);
        int iCount = 0;
        while (!qPos.isEmpty()) {
            int iSize = qPos.size();
            while (iSize-- > 0) {
                int iPos = qPos.poll();
                arrCount[iPos] = ++iCount;
                for (int iNextPos : arrNode[iPos]) {
                    if (!bVisited[iNextPos]) {
                        bVisited[iNextPos] = true;
                        qPos.add(iNextPos);
                    }
                }
            }
        }
        for (int i = 1; i <= iN; ++i) {
            sb.append(arrCount[i] + "\n");
        }
        System.out.println(sb);
    }
}
