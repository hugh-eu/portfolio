
public class Student {
	
	// 속성
	String name;
	int grade;
	int age;
	String major;
	
	// 생성자
	public Student() {
		this.name = "아무개";
		this.grade = 1;
		this.age = 19;
		this.major = "컴공";
	}
	
	public Student(String name, int grade, int age, String major) {  // 변수명을 약어로 사용하고 this 안 붙일 수 있지만 개체 생성시 확인하기 위해 풀 단어로 적기 추천
		this.name = name;
		this.grade = grade;
		this.age = age;
		this.major = major;
	}

	// 기능
	public void printStudentInfo() {
		System.out.println("name : " + this.name);
		System.out.println("grade : " + this.grade);
		System.out.println("age : " + this.age);
		System.out.println("major : " + this.major);
	}
	
	
}
