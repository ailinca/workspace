
public interface Category {
	
	public String toString();
	public String getName();
}


class Food implements Category {
	String name;
	public Food() {
		name = new String();
	}
	public Food(String n) {
		name = n;
	}
	public String getName() {
		return name;
	}
	
	public String toString() {
		return "Category:" + name;
	}
}
class Beverage implements Category {
	String name;
	public Beverage() {
		name = new String();
	}
	public Beverage(String n) {
		name = n;
	}
	public String getName() {
		return name;
	}
	
	public String toString() {
		return "Category:" + name;
	}
}
class Clothing implements Category {
	String name;
	public Clothing() {
		name = new String();
	}
	public Clothing(String n) {
		name = n;
	}
	public String getName() {
		return name;
	}
	
	public String toString() {
		return "Category:" + name;
	}
}
class Gift implements Category {
	String name;
	public Gift() {
		name = new String();
	}
	public Gift(String n) {
		name = n;
	}
	public String getName() {
		return name;
	}
	
	public String toString() {
		return "Category:" + name;
	}
}
class Entertainment implements Category {
	String name;
	public Entertainment() {
		name = new String();
	}
	public Entertainment(String n) {
		name = n;
	}
	public String getName() {
		return name;
	}
	
	public String toString() {
		return "Category:" + name;
	}
}
class Taxes implements Category {
	String name;
	public Taxes() {
		name = new String();
	}
	public Taxes(String n) {
		name = n;
	}
	public String getName() {
		return name;
	}
	
	public String toString() {
		return "Category:" + name;
	}
}