import java.util.Date;
import java.util.HashMap;
import java.util.LinkedList;

public class Brain {

	public LinkedList<GenericPair<Category, HashMap<Date,  LinkedList<Product>>>> fullmap;
	int totalcash;
	int totalspend;

	public Brain()
	{
		this.totalcash = 0;
		this.totalspend = 0;
		this.fullmap = new LinkedList<GenericPair<Category, HashMap<Date,  LinkedList<Product>>>>();
	}

	public Brain(int c)
	{
		this.totalcash = c;
		this.totalspend = 0;
		this.fullmap = new LinkedList<GenericPair<Category, HashMap<Date,  LinkedList<Product>>>>(); 
	}

	public int getCash()
	{
		return this.totalcash;
	}

	public int getSpend()
	{
		return this.totalspend;
	}

	public int getRemaining()
	{
		return (this.totalcash - this.totalspend);
	}

	public void addProduct(Product p)
	{
		for(GenericPair<Category, HashMap<Date,  LinkedList<Product>>> itr : fullmap) {
			if(itr.getFirst().getName().equals(p.getCategory().getName()))  {
				if(itr.getSecond().containsKey(p.getDate())) {
					itr.getSecond().get(p.getDate()).add(p);
				} else {
					LinkedList<Product> list = new LinkedList<Product>() ;
					list.add(p);
					itr.getSecond().put(p.getDate(), list);
				}
			}
		}
	}

	public void delProduct(Product p)
	{
		for(GenericPair<Category, HashMap<Date,  LinkedList<Product>>> itr : fullmap) {
			if(itr.getFirst().getName().equals(p.getCategory().getName()))  {
				if(itr.getSecond().containsKey(p.getDate())) {
					itr.getSecond().get(p.getDate()).remove(p); 
				}else System.out.println("You did not purchase anything at that date");
			}else System.out.println("There is no category with that name"); // ......
		}
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	

