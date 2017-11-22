/*
Spencer Hyland
03-60-212
Assignment 1
Question 4
*/
import java.net.URL;
import javax.swing.*;

public class q4{
	public static void main(String[] args) throws Exception {
		URL imageLocation = new URL("https://vignette.wikia.nocookie.net/southpark/images/d/d3/SeasonsGreetings1.jpg/revision/latest?cb=20170108175042");
		JOptionPane.showMessageDialog(null, "How's it going", "Title",
				JOptionPane.PLAIN_MESSAGE, new ImageIcon(imageLocation));
	}
}