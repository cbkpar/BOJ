import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int iN = Integer.parseInt(st.nextToken());
        int iM = Integer.parseInt(st.nextToken());
        int iA = 100 - iN;
        int iB = 100 - iM;
        int iC = 100 - (iA + iB);
        int iD = iA * iB;
        int iQ = (iN * iM) / 100;
        int iR = (iN * iM) % 100;
        System.out.println(iA + " " + iB + " " + iC + " " + iD + " " + (iD / 100) + " " + (iD % 100));
        System.out.println(iQ + " " + iR);
    }
}
