import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int iN = Integer.parseInt(br.readLine());
        HashMap<String, Integer> mapPeople = new HashMap<String, Integer>();
        for (int i = 0; i < iN; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String strTime = st.nextToken();
            String strName = st.nextToken();
            int iTime = TimeToInt(strTime);
            if (mapPeople.containsKey(strName)) {
                mapPeople.put(strName, mapPeople.get(strName) + iTime);
            } else {
                mapPeople.put(strName, iTime);
            }
        }
        ArrayList<People> arrPeople = new ArrayList<>();
        for (String strName : mapPeople.keySet()) {
            arrPeople.add(new People(strName, CalcCost(mapPeople.get(strName))));
        }
        Collections.sort(arrPeople, new Comparator<People>() {
            @Override
            public int compare(People o1, People o2) {
                if (o1.iCost == o2.iCost) {
                    return o1.strName.compareTo(o2.strName);
                } else {
                    return o2.iCost - o1.iCost;
                }
            }
        });
        for (People people : arrPeople) {
            sb.append(people.strName + " " + people.iCost + "\n");
        }
        System.out.println(sb);
    }

    private static int TimeToInt(String strTime) {
        StringTokenizer st = new StringTokenizer(strTime, ":");
        int iHour = Integer.parseInt(st.nextToken());
        int iMinute = Integer.parseInt(st.nextToken());
        return iHour * 60 + iMinute;
    }

    private static int CalcCost(int iTime) {
        int iCost = 10;
        if (iTime > 100) {
            iCost += ((iTime - 51) / 50) * 3;
        }
        return iCost;
    }
}

class People {
    public People(String strName, int iCost) {
        this.strName = strName;
        this.iCost = iCost;
    }

    String strName;
    int iCost;
}
