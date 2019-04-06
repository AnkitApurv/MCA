/*
@desc Swing

Create a GUI using Swing components to accept the following details of a student: 
RegisterNumber, Name, Gender, Semester, Class, DateOfBirth and LanguagesKnown.

@name Ankit Apurv
@roll 180970042
@date 02/04/19
*/

class SwingTest {
	public static void main(String ... args) {
		JFrame frame = new Sform();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		return;
	}
}

class Sform extends JFrame {
	public Sform() {
		createForm();
	}
	
	private void createForm() {
		//event listener in the form
		ActionListener al = new EventListener();
		
		//form's layout
		JPanel panel = new JPanel();
		panel.setLayout(new GridLayout(8, 2)); 
		
		//accept button, one and only
		JButton button = new JButton("Accept!");
		button.addActionListener(al);
		
		//labels
		
		
		//textfields
		
		
		//add all components to the panel
		
		
		//prepare form
		this.setContentPane(panel);
		this.pack();
		this.setTitle("Student Details");
		this.setResizable(false);
		
		return;
	}
	
	class EventListener implements ActionListener {
		public void actionPerformed(ActionEvent ae) {
			//write to label, "accepted"
		}
	}
}