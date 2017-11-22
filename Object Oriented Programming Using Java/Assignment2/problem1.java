/*
 Spencer Hyland
 104449507
 03-60-212
 Assignment 2
 Problem 1
 */
import javax.swing.*;
import java.awt.*;

public class problem1{

    public static void main(String[] args){

        JFrame window = new JFrame();
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setBounds(0, 0, 500, 400);
        window.getContentPane().add(new Scene1());
        window.setVisible(true);

    }

}

class Scene1 extends JComponent {
	private static final long serialVersionUID = 1L;

	public void paint(Graphics Light) {

        //Drawing background
        Light.setColor(Color.CYAN);
        Light.fillRect(0, 0, 500, 400);

        //Drawing stop light frame
        Light.setColor(Color.ORANGE);
        Light.fillRect(50, 40, 100, 300);

        
        //Drawing non lit lights
        Light.setColor(Color.BLACK);
        Light.fillOval(65, 163, 70, 70);
        Light.fillOval(65, 250, 70, 70);
        
        //Drawing RED light
        Light.drawOval(65, 75, 70, 70);
        Light.setColor(Color.RED);
        Light.fillOval(65, 75, 70, 70);

        //Drawing caution light frame
        Light.setColor(Color.ORANGE);
        Light.fillRect(200, 40, 100, 300);
        
        //Drawing non lit lights
        Light.setColor(Color.BLACK);
        Light.fillOval(215, 75, 70, 70);
        Light.fillOval(215, 250, 70, 70);
        
         //Drawing yellow light
        Light.drawOval(215, 163, 70, 70);
        Light.setColor(Color.YELLOW);
        Light.fillOval(215, 163, 70, 70);
        
        //Drawing caution light frame
        Light.setColor(Color.ORANGE);
        Light.fillRect(350, 40, 100, 300);
        
        //Drawing non lit lights
        Light.setColor(Color.BLACK);
        Light.fillOval(365, 163, 70, 70);
        Light.fillOval(365, 75, 70, 70);
        
        //Drawing green light
        Light.drawOval(365, 250, 70, 70);
        Light.setColor(Color.GREEN);
        Light.fillOval(365, 250, 70, 70);
        
    }

}