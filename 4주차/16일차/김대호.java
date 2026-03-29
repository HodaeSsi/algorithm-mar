import java.util.*;
import java.io.*;

public class Main {
    static final int INF = 1000000000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[][] dp = new int[K + 1][4];

        for (int i = 0; i <= K; i++) {
            Arrays.fill(dp[i], INF);
        }

        dp[0][0] = 0;

        for (int i = 0; i <= K; i++) {
            for (int j = 0; j < 4; j++) {
                if (dp[i][j] == INF) continue;

                if (i + A <= K) {
                    dp[i + A][(j + 3) % 4] = Math.min(dp[i + A][(j + 3) % 4], dp[i][j] + 1);
                }

                if (i + B <= K) {
                    dp[i + B][(j + 1) % 4] = Math.min(dp[i + B][(j + 1) % 4], dp[i][j] + 1);
                }

                if (i + C <= K) {
                    dp[i + C][(j + 2) % 4] = Math.min(dp[i + C][(j + 2) % 4], dp[i][j] + 1);
                }
            }
        }

        int result = dp[K][0];
        if (result >= INF) {
            System.out.println("-1");
        } else {
            System.out.println(result);
        }
    }
}