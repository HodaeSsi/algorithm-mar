import java.util.*;
import java.io.*;

public class Main {
    // "m개 이하의 돌로 모든 사이 거리를 min이상으로 유지할 수 있는가"
    private static boolean isPossible(long minDistance, int[] rocks, long totalDistance, int m) {
        int removeCount = 0;
        int pos = 0;

        for (int i = 0; i < rocks.length; i++) {
            if (rocks[i] - pos < minDistance) {
                removeCount++;
            } else {
                pos = rocks[i];
            }
        }

        if (totalDistance - pos < minDistance) {
            removeCount++;
        }

        return removeCount <= m;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long d = Long.parseLong(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] rocks = new int[n];
        for (int i = 0; i < n; i++) {
            rocks[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(rocks);

        long low = 1;
        long high = d;
        long answer = 0;
        while (low <= high) {
            long mid = (low + high) / 2;

            if (isPossible(mid, rocks, d, m)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        System.out.println(answer);
    }
}