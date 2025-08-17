import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class C_2120_GodTree {
    public static void main(String[] args) throws IOException {
        BufferedScanner input = new BufferedScanner();
        BufferedOutput output = new BufferedOutput();

        int tasks = input.nextInt();
        while (tasks-- > 0) {
            long length = input.nextLong();
            long score = input.nextLong();

            if (score < length || score > length * (length + 1) / 2) {
                output.println(-1);
            } else {
                int[] result = new int[(int) length];

                long remainder = score - length;
                int maxDelta = (int) (length - 1);
                int number = 1;
                while (remainder > 0) {
                    int delta = maxDelta < remainder ? maxDelta : (int) remainder;

                    result[delta] = number;
                    remainder -= delta;
                    number++;
                }

                for (int i = 0; i < length; i++) {
                    if (result[i] == 0) {
                        result[i] = number;
                        number++;
                    }
                }

                output.println(result[0]);
                for (int i = 1; i < length; i++) {
                    output.println(result[i - 1] + " " + result[i]);
                }
            }
        }

        output.flush();
    }

    private static class BufferedScanner {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        public BufferedScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(nextToken());
        }

        public int[] nextIntArray(int length) throws IOException {
            int[] numbers = new int[length];
            for (int i = 0; i < length; i++) {
                numbers[i] = nextInt();
            }

            return numbers;
        }

        public long[] nextLongArray(int length) throws IOException {
            long[] numbers = new long[length];
            for (int i = 0; i < length; i++) {
                numbers[i] = nextLong();
            }

            return numbers;
        }

        public String nextLine() throws IOException {
            tokenizer = null;
            return reader.readLine();
        }

        private String nextToken() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }

            return tokenizer.nextToken();
        }
    }

    private static class BufferedOutput {
        private final StringBuilder result;

        public BufferedOutput() {
            result = new StringBuilder();
        }

        public void print(Object object) {
            result.append(object);
        }

        public void println(Object object) {
            result.append(object).append("\n");
        }

        public void flush() {
            System.out.println(result);
            System.out.flush();
            result.setLength(0);
        }
    }
}
