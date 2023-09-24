import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class start {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String input;
        try {
            while ((input = reader.readLine()) != null) {
                if (input.equalsIgnoreCase("server")) {
                    runServer();
                } else if (input.equalsIgnoreCase("client")) {
                    runClient();
                } else {
                    System.out.println("Invalid input. Please enter 'server' or 'client'.");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void runServer() {
        // 在此处编写运行 Main.java 的代码
        System.out.println("Running Main.java");
    }

    private static void runClient() {
        // 在此处编写运行 Main2.java 的代码
        System.out.println("Running Main2.java");
    }
}