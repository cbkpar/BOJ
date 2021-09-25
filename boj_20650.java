import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i;
		int[] arr = new int[7];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (i = 0; i < 7; i++) arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);
		System.out.println(arr[0] + " " + arr[1] + " " + (arr[6] - arr[0] - arr[1]));
	}
}
