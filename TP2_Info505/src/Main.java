
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tab tab = new Tab();
		tab.setDecr();
		System.out.println(tab.toString());
		long debut = System.currentTimeMillis();
		tab.triShell();
		System.out.println(System.currentTimeMillis()-debut + "\n");
		System.out.println(tab.toString());
	}
}
