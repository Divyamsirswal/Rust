import java.awt.*;
import java.awt.event.*;

public class jtest extends Frame implements ActionListener {
    private Label a, b;
    private TextField t1;
    private TextField t2;
    private Button c;

    public jtest() {
        setLayout(new FlowLayout());

        a = new Label("Name : ");
        t1 = new TextField(20);

        b = new Label("Password : ");
        t2 = new TextField(20);
        t2.setEchoChar('*');

        c = new Button("click me");

        add(a);
        add(t1);
        add(b);
        add(t2);
        add(c);

        c.addActionListener(this);

        setTitle("Divyam");
        setVisible(true);
        setSize(400, 300);
    }

    public void actionPerformed(ActionEvent e) {
        String str1 = t1.getText();
        String str2 = t2.getText();

        System.out.println("Name: " + str1);
        System.out.println("Password: " + str2);
    }

    public static void main(String args[]) {
        jtest j = new jtest();

        j.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
