import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int[] arrParent;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int iN = Integer.parseInt(st.nextToken());
            int iM = Integer.parseInt(st.nextToken());
            if (iN == 0 && iM == 0) {
                break;
            }
            arrParent = new int[iN];
            for (int i = 0; i < iN; ++i) {
                arrParent[i] = i;
            }
            ArrayList<Road> arrRoad = new ArrayList<>();
            int iSumCost = 0;
            while (iM-- > 0) {
                st = new StringTokenizer(br.readLine());
                int iS = Integer.parseInt(st.nextToken());
                int iE = Integer.parseInt(st.nextToken());
                int iCost = Integer.parseInt(st.nextToken());
                arrRoad.add(new Road(iS, iE, iCost));
                iSumCost += iCost;
            }
            Collections.sort(arrRoad, new Comparator<Road>() {
                @Override
                public int compare(Road o1, Road o2) {
                    return o1.iCost - o2.iCost;
                }
            });
            int iCount = 0;
            int iSize = arrRoad.size();
            for (int i = 0; i < iSize; ++i) {
                Road tRoad = arrRoad.get(i);
                if (Find(tRoad.iS) != Find(tRoad.iE)) {
                    Union(tRoad.iS, tRoad.iE);
                    ++iCount;
                    iSumCost -= tRoad.iCost;
                }
                if (iCount + 1 == iN) {
                    break;
                }
            }
            sb.append(iSumCost + "\n");
        }
        System.out.println(sb);
    }

    private static int Find(int iX) {
        if (arrParent[iX] == iX) {
            return iX;
        }
        return arrParent[iX] = Find(arrParent[iX]);
    }

    private static void Union(int iA, int iB) {
        iA = Find(iA);
        iB = Find(iB);
        arrParent[iA] = iB;
    }
}

class Road {
    int iS, iE, iCost;

    public Road(int iS, int iE, int iCost) {
        this.iS = iS;
        this.iE = iE;
        this.iCost = iCost;
    }
}
