import java.io.*;
import java.util.*;

class Main {
	public static final int[] dy = {0, -1, 1, 0, 0, -1, -1, 1, 1};
	public static final int[] dx = {0, 0, 0, -1, 1, -1, 1, 1, -1};
	
	public static int[][] map = new int[8][8];
	
	public static boolean bfs() {
		Queue<int[]> q = new ArrayDeque<>(); // {y, x, depth}
		boolean[][] visited = new boolean[8][8];
		
		if (map[7][0] == 1) {
			return false;
		}
		
		q.offer(new int[] {7,0,0});
		visited[0][0] = true;
		
		while (!q.isEmpty()) {
			int[] now = q.poll();
			
			for (int i = 0; i < 9; i++) {
				int ny = now[0] + dy[i];
				int nx = now[1] + dx[i];
				
				if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8) continue;
				if (now[2] + 1 >= 8 && visited[ny][nx]) continue;
				if ((1 << now[2] & map[ny][nx]) > 0
						|| (1 << (now[2] + 1) & map[ny][nx]) > 0) continue;
				
				if (ny == 0 && nx == 7) return true;
				
				q.offer(new int[] {ny, nx, now[2] + 1});
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int i = 0; i < 8; i++) {
			String line = br.readLine();
			for (int j = 0; j < 8; j++) {
				if (line.charAt(j) == '#') {
					for (int k = 0; k < 8 - i; k++) {
						map[i+k][j] |= 1 << k;
					}
				}
			}
		}
		
		System.out.println(bfs() ? "1" : "0");
		
		return;
	}
	
	public static String display() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[0].length; j++) {
				sb.append(map[i][j] + " ");
			}
			sb.append("\n");
		}
		
		return sb.toString();
	}
}