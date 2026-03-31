import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int[] train = new int[n + 1];
        int[] prefixSum = new int[n + 1];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            train[i] = Integer.parseInt(st.nextToken());
            prefixSum[i] = prefixSum[i - 1] + train[i];
        }
        
        int limit = Integer.parseInt(br.readLine());
        
        // dp[기관차 수(1~3)][객차 번호]
        int[][] dp = new int[4][n + 1];
        
        // DP
        for (int i = 1; i <= 3; i++) {
            for (int j = i * limit; j <= n; j++) {
                int currentSegmentSum = prefixSum[j] - prefixSum[j - limit];
                // 현재 구간을 선택하지 않음 vs 현재 구간을 선택함 + 이전 기관차들의 최적값
                dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j - limit] + currentSegmentSum);
            }
        }
        
        System.out.println(dp[3][n]);
    }
}