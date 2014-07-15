import java.util.Date;


public class Product {

	String name;
	float price;
	Category category;
	Date date;
	boolean shoud_not_buy;
	boolean tracked;
	
	public Product()
	{
		this.name = new String();
		this.price = 0;
		this.category = null;
		this.date = new Date();
		this.shoud_not_buy = false;
		this.tracked = false;
	}
	
	public Product(String n, float p, Category c, boolean s, boolean t)
	{
		this.name = n;
		this.price = p;
		this.category = c;
		this.shoud_not_buy = s;
		this.tracked = t;
		this.date = new Date();
	}
	
	public String getName()
	{
		return this.name;
	}
	
	public float getPrice()
	{
		return this.price;
	}
	
	public Date getDate()
	{
		return this.date;
	}
	
	public Category getCategory()
	{
		return this.category;
	}
	
	public boolean getSNB()
	{
		return this.shoud_not_buy;
	}
	
	public boolean getTRK()
	{
		return this.tracked;
	}
	
	public String toString()
	{
		return this.name + " " + this.price + "$ Category: " + this.category + 
				" Unrecommended: " + this.shoud_not_buy + " Tracked: " + this.tracked;
	}
	
}
