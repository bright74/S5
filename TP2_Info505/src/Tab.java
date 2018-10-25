
public class Tab {
	
	final static int TAILLEDEFAUT = 10000;
	final static int MULTRAND = 1000;
	private int tab[];	

	public Tab(){
		this(TAILLEDEFAUT);
	}
	
	public Tab(int taille){
		this.tab = new int[taille];
	}
	
	//méthodes-Get-Set
	
	public int getTaille(){
		return TAILLEDEFAUT;
	}
	
	public int[] getTab(){
		return this.tab;
	}
	
	public void setTab(int[] tab){
		this.tab = tab;
	}
	
	public int getElem(int rg){
		return this.getTab()[rg];
	}
	
	public void setElem(int elem, int rg){
		this.getTab()[rg] = elem;
	}
	
	//méthodes-AUTRES
	
	public void setDecr(){
		for(int i = this.getTaille()-1; i>0;i--){
			this.setElem(i, this.getTaille()-i);
		}
	}
	
	public void setAlea(int rg){
		this.setElem((int)(Math.random()*MULTRAND), rg);
	}
	
	public void tabAlea(){
		for (int i = 0; i<this.getTaille(); i++){
			this.setAlea(i);
		}
	}
	
	public String toString(){
		String res = "";
		for (int i = 0; i<this.getTaille(); i++){
			res = res + this.getElem(i) + "\n";
		}
		return res;
	}
	
	public void permut(int rg1, int rg2){
		int temp;
		temp = this.getElem(rg1);
		this.setElem(this.getElem(rg2), rg1);
		this.setElem(temp, rg2);
	}
	
	public void triShell(){
		int taille = this.getTaille();
		if (taille>1)
		{
			int j;
			int k = taille;
			do
			{
				k = k/2;
				for(int i=0; i+k<taille;i++){
					if(this.getElem(i)>this.getElem(i+k)){
						this.permut(i, i+k);
						j=i-k;
						while(j>=0 && (this.getElem(j)>this.getElem(j+k))){
							this.permut(j, j+k);
							j-=k;
						}
					}
				}
			} while (k>1);
		}
	}
	
	
}
