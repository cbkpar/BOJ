import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int iFrom = BinaryToInt(br.readLine());
        int iDest = BinaryToInt(br.readLine());
        Queue<Integer> QueueNumber = new LinkedList<>();
        boolean[] bVisited = new boolean[2048];
        QueueNumber.add(iFrom);
        bVisited[iFrom] = true;
        int iCount = 0;
        while (!QueueNumber.isEmpty()) {
            int iSize = QueueNumber.size();
            while (iSize-- > 0) {
                int iNumber = QueueNumber.poll();
                if (iNumber == iDest) {
                    System.out.println(iCount);
                    return;
                }
                if (iNumber + 1 < 2048 && !bVisited[iNumber + 1]) {
                    bVisited[iNumber + 1] = true;
                    QueueNumber.add(iNumber + 1);
                }
                if (iNumber - 1 >= 0 && !bVisited[iNumber - 1]) {
                    bVisited[iNumber - 1] = true;
                    QueueNumber.add(iNumber - 1);
                }
                for (int i = 1; i <= 10; ++i) {
                    if (iNumber >= 1 << i) {
                        if ((iNumber & 1 << (i - 1)) == 1 << (i - 1)) {
                            if (!bVisited[iNumber - (1 << (i - 1))]) {
                                bVisited[iNumber - (1 << (i - 1))] = true;
                                QueueNumber.add(iNumber - (1 << (i - 1)));
                            }
                        } else {
                            if (!bVisited[iNumber + (1 << (i - 1))]) {
                                bVisited[iNumber + (1 << (i - 1))] = true;
                                QueueNumber.add(iNumber + (1 << (i - 1)));
                            }
                        }
                    } else {
                        break;
                    }
                }
            }
            ++iCount;
        }
    }

    private static int BinaryToInt(String str) {
        int iNumber = 0;
        int iPow = 1;
        int iSize = str.length();
        for (int i = iSize - 1; i >= 0; --i) {
            if ('1' == str.charAt(i)) {
                iNumber += iPow;
            }
            iPow *= 2;
        }
        return iNumber;
    }
}
