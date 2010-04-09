
public class Triangle {

	protected int rootVal = 0;
	private int sum = 0;
	private Triangle[] children = {null,null};
	
	public Triangle(int val, Triangle a, Triangle b){
		rootVal = val;
		children[0] = a;
		children[1] = b;
		if (children[0].getSum() > children[1].getSum())
			sum = children[0].getSum();
		else
			sum = children[1].getSum();
	}

	public int getSum() {
		return sum;
	}
	
	
}
