
public class NewStudent {

	int grade = 1;  // 학년
	int classNo;  // 반번호
	int studentNo;  // 학번
	String studentName;  // 이름
	boolean absence = false;  // 휴학여부
	
	public NewStudent(int classNo, int studentNo, String studentName) {  // 생성자
		this.classNo = classNo;
		this.studentNo = studentNo;
		this.studentName = studentName;
	}
	
	public NewStudent(int grade, int classNo, int studentNo, String studentName) {  // 생성자 오버로딩
		this.grade = grade;
		this.classNo = classNo;
		this.studentNo = studentNo;
		this.studentName = studentName;
	}
	
	public NewStudent(int grade, int classNo, int studentNo, String studentName, boolean absence) {  // 생성자 오버로딩
		this.grade = grade;
		this.classNo = classNo;
		this.studentNo = studentNo;
		this.studentName = studentName;
		this.absence = absence;
	}
	
	public NewStudent() {  // 디폴트생성자, 생성자가 없으면 컴파일러가 자동으로 생성, 그러나 있을경우 만들지 않음, 잘 구문하기
		
	}
	
	public void printInfo() {
		System.out.println("학년 : " + this.grade);
		System.out.println("반   : " + this.classNo);
		System.out.println("학번 : " + this.studentNo);
		System.out.println("이름 : " + this.studentName);
		if (this.absence) {
			System.out.println("휴학 : O");
		} else {
			System.out.println("휴학 : X");
		}
	}
	
	
	
}
