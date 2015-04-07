import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

/**
 * Created by chintu on 4/6/15.
 */
public class ReverseWords {
    private static Path pathSmall = Paths.get("B-large-practice.in");
    private static Path output = Paths.get("B-large-practice.out");

    public static void main(String[] args) {
        Path file = pathSmall;
        int N;

        try {
            BufferedReader reader = Files.newBufferedReader(file, Charset.defaultCharset());
            BufferedWriter writer = Files.newBufferedWriter(output, Charset.defaultCharset());
            N = Integer.parseInt(reader.readLine());
            for (int i = 0; i < N ; i++) {
                String sentence = reader.readLine();
                String s = reverseSentence(sentence);
                writer.write("Case #" + Integer.toString(i+1) + ": " + s + '\n');
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static String reverseSentence(String sentence) {
        String res = "";
        String revWord = "";
        for(int i=sentence.length()-1; i>=0; i--){
            char c = sentence.charAt(i);
            if (' ' != c) {
                revWord = c + revWord;
            } else {
                res += revWord + c ;
                revWord = "";
            }
        }
        res += revWord;
        return res;
    }
}
