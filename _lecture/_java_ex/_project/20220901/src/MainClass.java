import java.time.LocalTime;
import java.util.Scanner;

//import java.util.Scanner;

//import java.time.LocalTime;

public class MainClass {  // 클래스명을 바꾸고 싶으면 블럭처리한 뒤 refactor>rename or explorer의 파일명 변경, 클래스명은 파일명과 동일
	
//	public int myMethod() {  // MainClass에 포함, 공개형 public, 클래스 내부에서 사용 private, protected, 반환값 int
//		return 0;
//	}
	
	
	public static void main(String[] args) {  // static, main 시작점을 바로 찾기위해 메모리 stack에 별도 보관
//		// String
//		//String str1 = new String("hello");  // FM
//		
//		LocalTime now = LocalTime.now();  // current time, ctrl+shift+o 단축키로 LocalTime import혹은 제거
//		System.out.println("before: " + now);
//		String str1 = "hello";  // c의 포인터처럼 str1에 "hello"의 주소값 저장하여 참조
//		for (int i = 0; i < 100000; i++) {
//			str1 = str1 + "h";
//		}
//		now = LocalTime.now();  // current time
//		System.out.println("after: " + now);
		
//		str1 = "hi";  // String은 변수값을 바꿀때마다 다른 메모리공간에 "hi" 만들고 그 주소값을 str1에 저장
//		// 자주 바꿀때마다 메모리 문제
//		// because
//		// StringBuffer, StringBuilder, 메모리 위치를 바꾸지 않고 크기를 늘였다 줄였다 하여 메모리 효율성 높임
		
//		now = LocalTime.now();  // current time
//		System.out.println("before: " + now);
//		StringBuffer sbf1 = new StringBuffer();  // 클래스 객체 생성, new 객체 생성 연산자
//		sbf1.append("hello");
//		for(int i =0;i < 100000;i++) {
//			sbf1.append("h");
//		}
//		now = LocalTime.now();  // current time
//		System.out.println("after: " + now);  // String과 StringBuffer 처리시간 계산
		
//		sbf1 = new StringBuffer();
//		sbf1.append("hihi");
//		sbf1.append(sbf1.toString() + "hi");
//		
//		StringBuilder sbd1 = new StringBuilder();
//		sbd1.append("hi");

//		// short, int, short
//		char c1 = 'a';  // 1byte
//		short num0 = 5;  // 2byte
//		int num1 = 10;  // 4byte
//		num1 = 20;  // 메모리에 값 자체 변경

//		// float, double
//		float flt1 = 3.14f;
//		double dbl1 = 3.141592;
		
//		// 입력
//		Scanner sc = new Scanner(System.in);  // 인자로 입력받는곳
//		System.out.print("이름을 입력하세요 : ");
//		String name = sc.next();  // 문자열입력 메소드
//		System.out.print("나이를 입력하세요 : ");
//		int age = sc.nextInt();  // 정수 입력 메소드
//		System.out.print("신장을 입력하세요 : ");
//		double height = sc.nextDouble();  // 실수(double) 입력 메소드, \n을 포함하지 않기 때문에 버퍼에 \n 남아있음
//		System.out.print("자기소개를 입력하세요 : ");
//		sc.nextLine();  // 버퍼에 남은 \n 처리
//		String intro = sc.nextLine();  // next와의 차이, nextLine \n 포함하여 받음
//		System.out.println("이름 : " + name);
//		System.out.println("나이 : " + age);
//		System.out.println("신장 : " + height);
//		System.out.println("소개 : " + intro);
		
		// 콘솔창 현재시간 출력
//		LocalTime now = LocalTime.now();
//		System.out.println("현재 시간 : " + now);
		
		// 국어, 영어, 수학 점수 입력 받아 출력
//		Scanner sc = new Scanner(System.in);
//		System.out.print("국어 점수 : ");
//		int korScr = sc.nextInt();
//		System.out.print("영어 점수 : ");
//		int engScr = sc.nextInt();
//		System.out.print("수학 점수 : ");
//		int matScr = sc.nextInt();
//		System.out.println("국어 : " + korScr + "점");
//		System.out.println("영어 : " + engScr + "점");
//		System.out.println("수학 : " + matScr + "점");
//		int totalScr = korScr + engScr + matScr;
//		double aveScr = totalScr / 3.0;
//		System.out.println("총점 : " + totalScr + "점, 평균 : " + (Math.round(aveScr * 100) / 100.0) + "점");
		
		// 사용자로부터 2개의 정수 입력 받아 사칙연산
//		Scanner sc = new Scanner(System.in);
//		System.out.print("첫번째 정수 : ");
//		int num1 = sc.nextInt();
//		System.out.print("두번째 정수 : ");
//		int num2 = sc.nextInt();
//		System.out.println(num1 + " + " + num2 + " = " + (num1+num2));
//		System.out.println(num1 + " - " + num2 + " = " + (num1-num2));
//		System.out.println(num1 + " * " + num2 + " = " + (num1*num2));
//		System.out.println(num1 + " / " + num2 + " = " + ((double)num1/num2));
		
		// 개인 정보 이름 나이 메일 주소 전화번호 입력받아 출력
//		Scanner sc = new Scanner(System.in);
//		System.out.print("이름 : ");
//		String name = sc.next();
//		System.out.print("나이 : ");
//		int age = sc.nextInt();
//		System.out.print("메일 : ");
//		String mail = sc.next();
//		System.out.print("주소 : ");
//		String addr = sc.next();
//		System.out.print("전화 : ");
//		String phone = sc.next();
//		System.out.println("이름 : " + name);
//		System.out.println("나이 : " + age);
//		System.out.println("메일 : " + mail);
//		System.out.println("주소 : " + addr);
//		System.out.println("전화 : " + phone);
		
		// 삼각형의 밑변과 높이를 입력, 삼각형의 넓이 출력
//		Scanner sc = new Scanner(System.in);
//		System.out.print("밑변 : ");
//		int base = sc.nextInt();
//		System.out.print("높이 : ");
//		int height = sc.nextInt();
//		System.out.println("삼각형의 넓이 : " + (Math.round((base * height / 2.0) * 10) / 10.0));
		
		
	}

}
