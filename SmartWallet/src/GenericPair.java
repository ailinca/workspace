public class GenericPair<firstParam, secondParam> {
	private firstParam first;
	private secondParam second;
	public GenericPair(firstParam first, secondParam second) {
		this.first = first;
		this.second = second;
	}
	
	public void setFirst(firstParam first) {
		this.first = first;
	}
	public void setSecond(secondParam second) {
		this.second = second;
	}
	public firstParam getFirst(){
		return this.first;
	}
	public secondParam getSecond() {
		return this.second;
	}
}