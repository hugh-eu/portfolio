
public class Car {
	
	// 속성
	int size = 5;  // 크기
	String color = "red";  // 색상
	int price = 50000000;  // 가격
	
	// 생성자
	public Car() {  // 생략가능, 없을 경우 컴파일러가 자동으로 생성, default 생성자, 객체를 메모리에 만드는 역할
		System.out.println("기본 생성자");  // 비워둬도 됨
	}
	
	// 기능
	public void goForward() {  // 전진
		System.out.println("전진");
	}
	
	public void goBackward() {  // 후진
		System.out.println("후진");		
	}
	
	public void stop() {  // 정지
		System.out.println("정지");
	}
	
	public void turn() {  // 턴
		System.out.println("턴");
	}
	
	
}
