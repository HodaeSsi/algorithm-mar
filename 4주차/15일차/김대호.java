import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int S = Integer.parseInt(br.readLine());

        boolean[][] visited = new boolean[2001][2001];
        
        Queue<int[]> q = new LinkedList<>();

        q.offer(new int[]{1, 0, 0});
        visited[1][0] = true;

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int s = curr[0];
            int c = curr[1];
            int t = curr[2];

            if (s == S) {
                System.out.println(t);
                return;
            }

            if (!visited[s][s]) {
                visited[s][s] = true;
                q.offer(new int[]{s, s, t + 1});
            }

            if (c > 0 && s + c <= 2000) {
                if (!visited[s + c][c]) {
                    visited[s + c][c] = true;
                    q.offer(new int[]{s + c, c, t + 1});
                }
            }

            if (s > 0) {
                if (!visited[s - 1][c]) {
                    visited[s - 1][c] = true;
                    q.offer(new int[]{s - 1, c, t + 1});
                }
            }
        }
    }
}