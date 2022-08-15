import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        String strPrefix = st.nextToken();
        while (st.hasMoreTokens()) {
            String strName = st.nextToken();
            int iSize = strName.length();
            String strPlus = "";
            String strPlusMid = "";
            for (int i = 0; i < iSize; ++i) {
                if ((strName.charAt(i) >= 'a' && strName.charAt(i) <= 'z') || (strName.charAt(i) >= 'A' && strName.charAt(i) <= 'Z')) {
                    strPlus += strName.charAt(i);
                } else {
                    for (int j = iSize - 2; j >= i; --j) {
                        if (strName.charAt(j) == '*' || strName.charAt(j) == '&') {
                            strPlusMid += strName.charAt(j);
                        } else {
                            strPlusMid += "[]";
                            --j;
                        }
                    }
                    break;
                }
            }
            sb.append(strPrefix + strPlusMid + " " + strPlus + ";\n");
        }
        System.out.println(sb);
    }
}
