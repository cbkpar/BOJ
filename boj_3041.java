import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] arr_y = new int[16];
		int[] arr_x = new int[16];
		for (int i = 0; i < 16; i++) {
			arr_y[i] = i / 4;
			arr_x[i] = i % 4;
		}
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			String str = br.readLine();
			for (int j = 0; j < 4; j++) {
				if (str.charAt(j) == '.')
					continue;
				int tmp = str.charAt(j) - 'A';
				sum += Math.abs(arr_y[tmp] - i) + Math.abs(arr_x[tmp] - j);
			}
		}
		System.out.println(sum);
	}
}
