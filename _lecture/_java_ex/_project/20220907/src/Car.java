
public class Car {

	public String color;
	public int length;
	public int price;
	public int displacement;
	public int speed;

	public Car() {
		System.out.println(" ---- Car default constructor ---- ");
	}

	public Car(String color, int length, int price, int displacement) {
		this.color = color;
		this.length = length;
		this.price = price;
		this.displacement = displacement;
	}
	
	public void goForward() {
		System.out.println("[Car] goForward() Called.");
	}
	
	public void goForward(int speed) {
		this.speed = speed;  // 지역변수를 전역변수로
		System.out.println(String.format("goForward at %dkm/h", this.speed));
	}
	
	public void goForward(int speed, int after) {
		System.out.println(String.format("goForward at %dkm/h after %d hours", speed, after));
	}

	public void goBackward() {
		System.out.println("[Car] goBackward() Called.");
	}
	
	public void doStop() {
		System.out.println("[Car] doStop() Called.");
	}

	public void testCar() {
		this.goForward();  // FM
		goBackward();
		doStop();
	}
	
	
	
	// getters, setters
	public void setPrice(int price, String password) {
		if (password == "1234") {
			this.price = price;
			System.out.println("setPrice Done.");
		} else {
			System.out.println("Password Error.");
		}
	}

	public int getPrice() {
		return this.price;
	}

	
}
