import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        if (s == null || s.isEmpty()) return;

        Deque<Long> nums = new LinkedList<>();
        Deque<Character> ops = new LinkedList<>();

        StringBuilder sb = new StringBuilder();
        int startIdx = 0;

        if (s.charAt(0) == '-') {
            sb.append('-');
            startIdx = 1;
        }

        for (int i = startIdx; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                nums.addLast(Long.parseLong(sb.toString()));
                ops.addLast(c);
                sb.setLength(0);
            } else {
                sb.append(c);
            }
        }
        nums.addLast(Long.parseLong(sb.toString()));

        while (!ops.isEmpty()) {
            if (ops.size() == 1) {
                long n1 = nums.pollFirst();
                long n2 = nums.pollFirst();
                nums.addFirst(calculate(n1, ops.pollFirst(), n2));
                break;
            }

            char leftOp = ops.peekFirst();
            char rightOp = ops.peekLast();

            int leftPriority = getPriority(leftOp);
            int rightPriority = getPriority(rightOp);

            boolean doFront;

            if (leftPriority > rightPriority) {
                doFront = true;
            } else if (rightPriority > leftPriority) {
                doFront = false;
            } else {
                long left1 = nums.pollFirst();
                long left2 = nums.pollFirst();
                long leftValue = calculate(left1, leftOp, left2);

                nums.addFirst(left2);
                nums.addFirst(left1);

                long right2 = nums.pollLast();
                long right1 = nums.pollLast();
                long rightValue = calculate(right1, rightOp, right2);

                nums.addLast(right1);
                nums.addLast(right2);

                if (leftValue >= rightValue) {
                    doFront = true;
                } else {
                    doFront = false;
                }
            }

            if (doFront) {
                long n1 = nums.pollFirst();
                long n2 = nums.pollFirst();
                nums.addFirst(calculate(n1, ops.pollFirst(), n2));
            } else {
                long n2 = nums.pollLast();
                long n1 = nums.pollLast();
                nums.addLast(calculate(n1, ops.pollLast(), n2));
            }
        }

        System.out.println(nums.peekFirst());
    }

    private static int getPriority(char op) {
        if (op == '*' || op == '/') return 1;
        return 0;
    }

    private static long calculate(long n1, char op, long n2) {
        switch (op) {
            case '+': return n1 + n2;
            case '-': return n1 - n2;
            case '*': return n1 * n2;
            case '/': return n1 / n2; // C++ 방식 정수 나눗셈 (자바의 기본 / 와 동일)
        }
        return 0;
    }
}