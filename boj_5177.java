import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        for (int i = 1; i <= n; i++) {
            boolean equal = true;
            if (!convert(br.readLine()).equals(convert(br.readLine()))) {
                equal = false;
            }
            if (i != 1) sb.append("\n");
            sb.append("Data Set " + i + ": " + (equal ? "equal\n" : "not equal\n"));
        }
        System.out.println(sb);
    }

    private static String convert(String str) {
        str = str.toLowerCase();
        str = str.replaceAll("[\\(\\{]", "\\[");
        str = str.replaceAll("[\\)\\}]", "\\]");
        str = str.replaceAll("[,]", ";");
        StringTokenizer st = new StringTokenizer(str);
        String tmp = st.nextToken();
        while (st.hasMoreTokens()) {
            boolean combine = false;
            if (tmp.charAt(tmp.length() - 1) == '[') combine = true;
            if (tmp.charAt(tmp.length() - 1) == ']') combine = true;
            if (tmp.charAt(tmp.length() - 1) == ';') combine = true;
            if (tmp.charAt(tmp.length() - 1) == '.') combine = true;
            if (tmp.charAt(tmp.length() - 1) == ':') combine = true;
            String tmpstr = st.nextToken();
            if (tmpstr.charAt(0) == '[') combine = true;
            if (tmpstr.charAt(0) == ']') combine = true;
            if (tmpstr.charAt(0) == ';') combine = true;
            if (tmpstr.charAt(0) == '.') combine = true;
            if (tmpstr.charAt(0) == ':') combine = true;
            if (!combine) tmp = tmp + " ";
            tmp = tmp + tmpstr;
        }
        return tmp;
    }
}
