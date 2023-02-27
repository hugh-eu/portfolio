
public class Student {
	// 속성
	public String name;
	public int grade;
	public int age;
	public String major;
	
	// 생성자
	public Student(String n, int g, int a, String m) {  // 속성 초기화를 위해 매개변수를 받아 초기화
		System.out.println("--- CONSTRUCTOR ---");
		this.name = n;  // Student 클래스의 속성, 전역 name을 가리키기위해 this, 파이썬의 self
		this.grade = g;
		this.age = a;
		this.major = m;
	}
	
	// 기능
	public void printStudentInfo() {
		System.out.println("Name : " + name);
		System.out.println("Grade : " + grade);
		System.out.println("Age : " + age);
		System.out.println("Major : " + major);
	}
}
