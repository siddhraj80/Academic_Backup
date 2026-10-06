import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.nio.Buffer;

public class Program15 {
    public static void main(String[] args){

        try {
            File f1 = new File("Student.txt");

            FileReader fReader = new FileReader(f1);

            int filedata= fReader.read();

            System.out.println(filedata);
            
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
