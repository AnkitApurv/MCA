import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

class SwingCalculator 
{
		public static void main(String[] args) 
		{
				JFrame frame = new Calculator();
				frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				frame.setVisible(true);
		}
}

class Calculator extends JFrame 
{
	
		private final Font BIGGER_FONT = new Font("Dialog", Font.PLAIN, 24);
		private JTextField textfield;       
		double savedValue 	= 	0.0;
		boolean firstDigit 	= 	true;
		String operator 	= 	"=";  			// Initial operator

		public Calculator() 
		{
				textfield = new JTextField("0", 15);
				textfield.setHorizontalAlignment(JTextField.RIGHT);
				textfield.setEnabled(false);
				textfield.setFont(BIGGER_FONT);
			  
				ActionListener actionListener = new EventListener();
				String buttonString = "789+456-123*0.C/=";
				JPanel buttonPanel = new JPanel();
				buttonPanel.setLayout(new GridLayout(5, 4)); 
				for (int i = 0; i < buttonString.length(); i++) 
				{
						String key = buttonString.substring(i, i+1);
						JButton button = new JButton(key);
						button.addActionListener(actionListener);
						button.setFont(BIGGER_FONT);
						buttonPanel.add(button);
				}
		
				JPanel panel = new JPanel();
				panel.setLayout(new BorderLayout(4, 4));
				panel.add(textfield, BorderLayout.NORTH );
				panel.add(buttonPanel , BorderLayout.CENTER);
				this.setContentPane(panel);
				this.pack();
				this.setTitle("Calculator");
				this.setResizable(false);
		}
		
		class EventListener implements ActionListener 
		{
				public void actionPerformed(ActionEvent event) 
				{
						String s = event.getActionCommand(); 
						if (s.equals("C"))
						{
								savedValue = 0.0;	textfield.setText("0");
						}
						else
						if ("0123456789.".indexOf (s) != -1)
						{
								if (firstDigit) 
								{
										firstDigit = false;	textfield.setText (s);
								} 
								else 
								{
										textfield.setText (textfield.getText() + s);
								}
						}
						else  																// Operator
						{
								if (!firstDigit) 
								{
										compute (textfield.getText());	firstDigit = true;
								}
								operator = s;
						}
				}
		
				public void compute (String s) 
				{
						double sValue = new Double (s).doubleValue();
						char c = operator.charAt (0);
						switch (c) 
						{
								case 	'='	:   savedValue 	= 		sValue;		break;
								case 	'+'	:   savedValue 	+= 	sValue;		break;
								case 	'-'	:   savedValue 	-= 	sValue;		break;
								case 	'*'	:   savedValue 	*= 	sValue;		break;
								case 	'/'	:   savedValue 	/= 	sValue;		break;
						}
						if (savedValue % 1 != 0)
								textfield.setText (String.valueOf(savedValue));
						else
								textfield.setText (String.valueOf((int) savedValue));
				}
		}

}
	