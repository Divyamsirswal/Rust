import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class swing extends JFrame {
	private JLabel l;
	private JTextField tf;
	private JButton b;

	public swing(){
		setLayout(new FlowLayout());
		setTitle("Divyam");
		setSize(300,200);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

		l = new JLabel("Name :");
		tf = new JTextField(15);
		b = new JButton("Click");


		add(l);
		add(tf);
		add(b);

		b.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				String n = tf.getText();
				JOptionPane.showMessageDialog(swing.this,"Hello "+n+"!","Message",JOptionPane.PLAIN_MESSAGE);
			}
		});
	}

	public static void main(String args[]){
		swing s = new swing();
		s.setVisible(true);
	}
}