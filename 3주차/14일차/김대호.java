import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        
        long totalSum = 0;
        long maxTwos = 0;
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int h = Integer.parseInt(st.nextToken());
            totalSum += h;
            maxTwos += (h / 2);
        }
        
        if (totalSum % 3 == 0 && maxTwos >= (totalSum / 3)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}