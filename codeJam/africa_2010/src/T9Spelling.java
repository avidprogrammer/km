import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;

/**
 * Created by chintu on 4/6/15.
 */
public class T9Spelling {
    public static HashMap<String, String> dict;
    static {
        dict = new HashMap<>();
        dict.put("a", "2"); dict.put("b", "22"); dict.put("c", "222");
        dict.put("d", "3"); dict.put("e", "33"); dict.put("f", "333");
        dict.put("g", "4"); dict.put("h", "44"); dict.put("i", "444");
        dict.put("j", "5"); dict.put("k", "55"); dict.put("l", "555");
        dict.put("m", "6"); dict.put("n", "66"); dict.put("o", "666");
        dict.put("p", "7"); dict.put("q", "77"); dict.put("r", "777"); dict.put("s", "7777");
        dict.put("t", "8"); dict.put("u", "88"); dict.put("v", "888");
        dict.put("w", "9"); dict.put("x", "99"); dict.put("y", "999"); dict.put("z", "9999");
        dict.put(" ", "0");
    }

    private static Path ipPath = Paths.get("africa_2010/C-large-practice.in");
    private static Path opPath = Paths.get("C-large-practice.out");

    public static void main(String[] args) throws IOException {
        BufferedReader reader = Files.newBufferedReader(ipPath, Charset.defaultCharset());
        BufferedWriter writer = Files.newBufferedWriter(opPath, Charset.defaultCharset());

        int N = Integer.parseInt(reader.readLine());
        for (int i = 0; i < N ; i++) {
            String sentence = reader.readLine();
            String t9Output = encryptT9(sentence);
            String outputStr = "Case #"+Integer.toString(i+1) + ": " + t9Output;
            writer.write(outputStr + "\n");
            System.out.println(outputStr);
        }
        writer.close();

    }

    private static String encryptT9(String sentence) {
        String res = "";
        String prevCode = "-";
        for (int i = 0; i < sentence.length(); i++) {
            String c = "" + sentence.charAt(i);
            String code = dict.get(c);
            if (prevCode.charAt(0) == code.charAt(0)) {
                res += " ";
            }
            res += code;
            prevCode =code;
        }
        return res;
    }
}
