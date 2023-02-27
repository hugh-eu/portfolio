//import java.util.Arrays;
//import java.util.ArrayList;
//import java.util.Scanner;

public class MainCls {

	public static void main(String[] args) {
		// while
//		int num = 1;
//		while (num < 10) {
//			System.out.println(String.format("2 x %d = %d", num, num*2));
//			num++;
//		}
		
		// do ~ while
		// 사용자에게 DM발송, 수신거부시 DM발송x
//		boolean receiveDMFlag = true;
//		do {
//			System.out.println("DM 발송");
//			System.out.println("1. 수신거부  2. 계속수신");
//			Scanner sc = new Scanner(System.in);
//			int selectedNum = sc.nextInt();
//			if (selectedNum == 1) {
//				receiveDMFlag = false;
//			} else {
//				receiveDMFlag = true;
//			}
//			sc.close();  // 자원 해제
//		} while (receiveDMFlag);
		
		// for ~ each
//		for (int i = 0; i < 5; i++) {
//			System.out.println(i);
//		}
//		ArrayList<Integer> myScores = new ArrayList<>();
//		myScores.add(90);
//		myScores.add(80);
//		myScores.add(70);
//		System.out.println(myScores);
//		for (int i = 0; i < myScores.size(); i++) {  // Iterator가 반복실행
//			System.out.println(myScores.get(i));
//		}
//		for (int score : myScores) {   // Iterator, 배열, 리스트 순차적 실행, 한단계씩밖에 못함, 
//			System.out.println(score);
//		}
		
//		int i = 1, sum = 0;
//		while (i < 1001) {
//			if (i % 3 == 0) {
//				sum += i;
//			}
//			i++;
//		}
//		System.out.println(sum);
		
//		for (int i = 1; i < 6; i++) {
//			for (int j = 1; j < i+1; j++) {
//				System.out.print("*");
//			}
//			System.out.println();
//		}
		
//		for (int i = 1; i < 101; i++) {
//			System.out.println(i);
//		}
		
//		int[] marks = {70, 60, 55, 75, 95, 90, 80, 80, 85, 100};
//		int sum = 0;
//		for (int mark : marks) {
//			sum += mark;
//		}
//		double average = sum / (double)marks.length;
//		System.out.println(average);
		
		//2차원 배열
//		int[][] nums = new int[2][3];
//		nums[0][0] = 1;
//		nums[0][1] = 2;
//		nums[0][2] = 3;
//		nums[1][0] = 4;
//		nums[1][1] = 5;
//		nums[1][2] = 6;
//		System.out.println(nums[0][2]);
		
//		int[][] scores = {{85, 90, 75},
//				          {75, 100, 70},
//				          {65, 80, 100},
//				          {50, 60, 70}};
//		for (int i = 0; i < scores.length; i++) {
//			int[] temp = scores[i];
//			for (int j = 0; j < temp.length; j++) {
//				System.out.println(temp[j]);
//			}
//		}
		
//		int[][][] scores = {{{80, 90, 100}, {75, 85, 85}, {80, 90, 100}, {90, 100, 100}},
//				           {{90, 95, 85}, {75, 65, 55}, {95, 65, 85}, {94, 95, 75}},
//				           {{85, 85, 90}, {45, 80, 95}, {85, 85, 90}, {85, 77, 84}}};
//		String[] subjects = {"국어", "영어", "수학"};
//		for (int i = 0; i < scores.length; i++) {
//			System.out.println(String.format(" # %d학기 성적", i+1));
//			for (int j = 0; j < scores[i].length; j++) {
//				System.out.print(String.format("[%d번 학생]  ", j+1));
//				for (int k = 0; k < scores[i][j].length; k++) {
//					System.out.print(String.format("%s:%3d점  ", subjects[k], scores[i][j][k]));
//				}
//				System.out.println();
//			}
//			System.out.println();
//		}
		
		
		/// 객체지향프로그래밍, OOP, object-oriented programming
		// reference, 메모리 주소값을 통해 참조
//		int num = 10;  // privitive type, 기초 데이터타입
//		System.out.println(num);
//		num = 100;  // num 위치에서 변경
//		System.out.println(num);
//		int[] nums1 = {1, 2, 3, 4, 5};  // nums가 배열의 첫주소 참조
//		System.out.println(nums1);  // 주소값
//		int[] nums2 = {6, 7, 8, 9, 0};
//		System.out.println(nums2);  // nums1과 다른 주소값
//		nums1 = nums2;  // nums1에 2의 주소값
//		System.out.println(Arrays.toString(nums1));
//		System.out.println(Arrays.toString(nums2));
//		int[] nums3 = {0, 0, 0, 0, 0};
//		System.out.println(Arrays.toString(nums3));
//		nums3 = nums1;
//		System.out.println(Arrays.toString(nums3));
//		nums3 = null;  // reference 끊기
//		System.out.println(nums3);
//		System.out.println(Arrays.toString(nums3));

		// 클래스를 통해 객체 생성, 클래스는 Java 프로그램 구성 단위
		// 클래스 = 속성 + 기능 + 기능(생성자)
		// Car 클래스
//		Car myCar = new Car();  // Car 객체생성1
//		Car yourCar = new Car();  // Car 객체생성2
//		Car ourCar = new Car();  // Car 객체생성3
//		myCar.goForward();
//		myCar.stop();
//		myCar.goBackward();
//		myCar.turn();
//		System.out.println(myCar.size);
//		System.out.println(myCar.price);
//		System.out.println(myCar.color);
//		myCar = null;
//		myCar.stop();  // 에러
		
		// Student
//		Student student1 = new Student("가나다", 1, 11, "코딩");  // 생성자를 통한 속성 초기화
//		System.out.println(student1.name);
//		System.out.println(student1.grade);
//		System.out.println(student1.age);
//		System.out.println(student1.major);
//		Student student2 = new Student("훅흐", 4, 29, "항공");  // 생성자를 통한 속성 초기화
//		System.out.println(student2.name);
//		System.out.println(student2.grade);
//		System.out.println(student2.age);
//		System.out.println(student2.major);
//		Student student3 = new Student("홍길동", 2, 60, "호형호제");  // 생성자를 통한 속성 초기화
//		student3.printStudentInfo();
		
	}

}
