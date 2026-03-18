import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] xCoords = new int[K];
        int[] yCoords = new int[K];

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            xCoords[i] = Integer.parseInt(st.nextToken());
            yCoords[i] = Integer.parseInt(st.nextToken());
        }

        int maxStars = 0;

        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                int currentX = xCoords[i];
                int currentY = yCoords[j];
                int count = 0;

                for (int k = 0; k < K; k++) {
                    if (xCoords[k] >= currentX && xCoords[k] <= currentX + L &&
                        yCoords[k] >= currentY && yCoords[k] <= currentY + L) {
                        count++;
                    }
                }
                
                if (count > maxStars) {
                    maxStars = count;
                }
            }
        }

        System.out.println(K - maxStars);
    }
}