import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Vector;

public class TestCls {
	
	public static void main(String[] args) {
		
		// 자료형
//		char chr = 'a';
//		String str = "hi";
//		String str1 = new String();
//		
//		StringBuffer str2 = new StringBuffer();  // 자주씀, new는 연산자, 객체를 생성해주는 객체생성연산자, new연산자
//		str2.append("hello");
//		str2.append(" ");
//		str2.append("java");
//		System.out.println(str2.toString());  // 어떤 출력이건 습관처럼 가능한 경우 toString() 붙이기
//		str2.insert(2, "eeee");  // 특정위치 문자열 삽입
//		System.out.println(str2.toString());
//		System.out.println(str2.substring(2, 7));  // 특정 범위
//		
//		StringBuilder str3 = new StringBuilder();  // StringBuffer 멀티스레드에서 상대적으로 안정, StringBuilder는 성능우수 순서대로
//		
//		short num1 = 1;  // 2
//		int num2 = 2;  // 4
//		long num3 = 30l;  // 8, 뒤에 l
//		
//		float num4 = 3.14f;  // 4, 뒤에 f
//		double num5 = 3.141592;  // 8
		
		// 진수표기
//		int num6 = 045;  // 8진수, 0으로 시작
//		int num7 = 0x12; // 16진수, 0x
		
		// 증감연산자
//		int num8 = 10;
//		num8++;
//		System.out.println("num8 = " + num8);
//		num8 = 10;
//		int i = 0;
//		i = i + num8++;  // 후위 증감연산
//		System.out.println("i + num8++ 후위연산 " + i);
//		num8 = 10;
//		i = 0;
//		i = i + ++num8;  // 전위 증감연산
//		System.out.println("i + ++num8 전위연산 " + i);
		
		// bool 타입
//		boolean flag = false;
//		if (flag) {
//			System.out.println("flag is true");
//		} else {
//			System.out.println("flag is false");
//		}
//		boolean flag2 = 2 > 1;
//		System.out.println("2 > 1?" + flag2);
		
//		String str4 = "hello";
//		String str5 = "hello";
//		System.out.println("str4 == str5" + str4 == str5);
//		System.out.println("str4 != str5" + str4 != str5);
//		System.out.println("str4.equals(str5)" + str4.equals(str5));  // ==
		
//		String str6 = "hello";
//		str6 = null;  // str6 객체 지우기, str 변수는 사용가능
//		str6 = "hi";
		
		
		/// str 메서드
//		// indexOf, 특정 문자, 문자열의 시작 위치, 인덱스 반환
//		String str7 = "Hi Hello Java!!";
//		System.out.println("o의 시작 인덱스 : " + str7.indexOf("o"));  // int, 7
//		System.out.println(str7.indexOf("k"));  // 없는 경우 -1 반환
//		
//		// contains, 문자, 문자열 포함 여부
//		String str8 = "hi hey hello";
//		boolean isStr = str8.contains("i h");
//		System.out.println(isStr);  // bool타입 반환
//		
//		// charAt, 특정 위치, 인덱스의 문자 리턴
//		String str9 = "abcdefghij";
//		System.out.println(str9.charAt(5));
//		
//		// replaceAll, 특정문자열을 모두 변경하여 리턴, 원본유지
//		String str10 = "hi java hello python";
//		System.out.println(str10.replaceAll("python", "java"));
//		System.out.println(str10);
//		
//		// substring, 특정 인덱스 범위의 문자열 리턴
//		String str11 = "hello java";
//		System.out.println(str11.substring(1, 5));
//		
//		// toUppercase, toLowerCase, 대문자, 소문자로
//		String str12 = "hihihihiHHHHHiiHiifei";
//		System.out.println(str12.toUpperCase());
//		System.out.println(str12.toLowerCase());
//		//advfawEF  // ctrl+shift+x, y 대문자 소문자 변환 단축키
//		
//		// split, 특정구분자로 문자열 나누기
//		String str13 = "a b c d e f g";
//		System.out.println(str13.split(" ")[1]);  // 배열반환
//		String[] tempArr = str13.split(" ");
//		System.out.println(Arrays.toString(tempArr));  // 배열을 str로 바꾸어 출력
		
		// 문자열 포매팅
//		// 오늘 (2일)의 날씨는 최저 기온이 19도이고 최고 기온이 30도입니다.
//		int date = 2;
//		double lowestTemp = 19.3242;
//		double highestTemp = 30.22222;
//		System.out.println(String.format("오늘 (%d일)의 날씨는 최저 기온이 %.1f도이고 최고 기온이 %.1f도입니다.", date, lowestTemp, highestTemp));  // 숫자도 모두 %s로 통일해도 됨
//		System.out.println();
//		System.out.println(String.format("%d %f %s %% \" \"", 10, 11.2, "hihi"));
//		System.out.printf("");  // format의 경우 리턴값이 있음, printf는 출력용도로 리턴없음
		
		// 배열(array)
//		int[] nums = new int[7];  // 배열 요소의 타입명시, 배열의 크기변경이 불가, 초기값 0
//		nums[0] = 1;
//		System.out.println(Arrays.toString(nums));
//		String[] strs;
//		strs = new String[7];  // 초기값 null
//		strs[0] = "hi";
//		System.out.println(Arrays.toString(strs));
//		int[] nums2 = {1, 2, 3, 4, 5};  // 가능
//		System.out.println(nums2.length);  // .length 배열의 길이
//		for (int i =0; i<nums2.length; i++) {
//			System.out.println(nums2[i]);
//		}
		
		/// 리스트, 사이즈 변경가능
//		// Vector, 하드웨어 성능이 나쁜경우 사용 추천
//		Vector<Integer> vt = new Vector<Integer>();
//		vt.add(1);
//		vt.add(2);
//		vt.add(3);
//		vt.add(4);
//		vt.add(5);
//		System.out.println(vt);
//		vt.remove(0);
//		System.out.println(vt);
//		System.out.println(vt.size());
//		System.out.println(vt.get(1));
//		System.out.println(vt.contains(1));
//		
//		
//		// ArrayList, 특별한 경우가 아닌이상 이걸쓰자
//		ArrayList<Integer> arrayList = new ArrayList<>();  // <Integer>: 제네릭스(generics), Integer: 기초데이터타입과 같은데 기능을 가진 클래스, 래퍼클래스
////		ArrayList<String> strList = new ArrayList<>();
////		ArrayList<Double> dobList = new ArrayList<>();
////		ArrayList<TestCls> myList = new ArrayList<>();
//		arrayList.add(1);
//		arrayList.add(2);
//		arrayList.add(3);
//		arrayList.add(4);
//		System.out.println(arrayList);
//		System.out.println(arrayList.size());  // .size 리스트의 길이
//		arrayList.add(5);
//		System.out.println(arrayList);
//		System.out.println(arrayList.size());
//		arrayList.remove(0);  // 특정 인덱스값 삭제
//		System.out.println(arrayList);
//		System.out.println(arrayList.get(2));  // 인덱스값 추출
//		System.out.println(arrayList.contains(6));  // 포함여부
//		
//			// join
//		ArrayList<String> weeks = new ArrayList<String>();
//		weeks.add("월");
//		weeks.add("화");
//		weeks.add("수");
//		weeks.add("목");
//		weeks.add("금");
//		weeks.add("토");
//		weeks.add("일");
//		String weeksStr = "";
//		for (int i = 0; i < weeks.size(); i++) {
//			weeksStr += weeks.get(i);
//		}
//		System.out.println(weeksStr);
//		String joinStr = String.join(", ", weeks);  // 리스트를 하나의 문자열로 만듬, 처음인자 구분자
//		System.out.println(joinStr);
//		
//			// sort
//		ArrayList<String> weeks = new ArrayList<String>();
//		weeks.add("월");
//		weeks.add("화");
//		weeks.add("수");
//		weeks.add("목");
//		weeks.add("금");
//		weeks.add("토");
//		weeks.add("일");
//		weeks.sort(Comparator.naturalOrder());  // 오름차순
//		System.out.println(weeks);
//		weeks.sort(Comparator.reverseOrder());  // 내림차순
//		System.out.println(weeks);
		
		/// 해시맵(HashMap), Dict 느낌
//		HashMap<String, Integer> hashMap = new HashMap<String, Integer>();
//		hashMap.put("홍", 12);  // 추가
//		hashMap.put("김", 13);
//		hashMap.put("이", 14);
//		hashMap.put("박", 11);
//		hashMap.put("최", 13);
//		hashMap.put("정", 16);
//		hashMap.put("윤", 19);
//		System.out.println(hashMap);
//		int age = hashMap.get("최");  // 키에 해당하는 밸류 추출
//		System.out.println(age);
//		System.out.println(hashMap.containsKey("류"));  // 키값 존재 여부
//		System.out.println(hashMap.size());  // 해시맵의 크기
//		System.out.println(hashMap.remove("김"));  // 삭제하며 밸류 반환
//		ArrayList<String> keys = new ArrayList<>(hashMap.keySet());  // Set 자료형으로 반환된 키들을 ArrayList로 변환
//		for (int i = 0; i < hashMap.size(); i++) {
//			System.out.println(keys.get(i));
//		}
		
		// LinkedList
//		LinkedList<Integer> linkedList = new LinkedList<Integer>();
//		linkedList.add(1);  // 추가
//		linkedList.add(2);
//		linkedList.add(3);
//		linkedList.add(4);
//		linkedList.add(5);
//		System.out.println(linkedList);
//		System.out.println(linkedList.get(1));  // 인덱스 값 추출
//		System.out.println(linkedList.remove(1));  // 해당 인덱스 삭제하며 값 반환
//		System.out.println(linkedList);
//		linkedList.clear();  // 모든 인덱스 삭제
//		System.out.println(linkedList);
//		linkedList = null;  // 객체 삭제
//		System.out.println(linkedList);
		
		// 형변환
//		String num = "123";
//		System.out.println(num.getClass().getName());  // 타입확인
//		int newNum = Integer.parseInt(num);  // 문자열 정수 변환
//		newNum += 1;
//		System.out.println(newNum);
//		
////	String newStr = "" + newNum;  // 문자열로 변환
//		String newStr = String.valueOf(newNum);  // 문자열로 변환
////	String newStr = Integer.toString(newNum);  // 문자열로 변환
//		System.out.println(newStr.getClass().getName());
//		
//		String dNum = "123.456";
//		double d = Double.parseDouble(dNum);  // double로
//		System.out.println(d + 1);
//		float f = Float.parseFloat(dNum);  //float로
//		System.out.println(f + 1);
//		
//		int n1 = 10;
////	double d1 = (double)n1;  // 강제 형변환
//		double d1 = n1;
//		System.out.println(d1);
//		double d2 = 123.456;
//		int n2 = (int)d2;
//		System.out.println(n2);
		
		// final, 값 한번만 설정 가능, 변경 불가
//		final int n3 = 100;  // 변경 불가
//		System.out.println(n3);
//		n3 = 200;  // 오류 발생
//		System.out.println(n3);
		
//		final ArrayList<String> arrayList = new ArrayList<String>();
//		arrayList.add("월");
//		arrayList.add("화");
//		arrayList.add("수");
//		System.out.println(arrayList);
//		arrayList = new ArrayList<String>();  // 에러
		
//		int korScr = 80, engScr = 75, MatScr = 55;
//		System.out.println(Math.round((korScr + engScr + MatScr) / 3.0 * 100) / 100.0);

//		int num1 = 13;
//		if (num1 % 2 == 0) {
//			System.out.println("짝수");
//		} else {
//			System.out.println("홀수");
//		}
		
//		String str1 = "881120-1068234";
//		System.out.println(str1.substring(0, 6));
//		System.out.println(str1.substring(7));
		
//		System.out.println(str1.charAt(7));
		
//		String a = "a:b:c:d";
//		System.out.println(a.replace(":", "#"));
		
//		ArrayList<Integer> myList = new ArrayList<Integer>(Arrays.asList(1, 3, 5, 4, 2));
//		myList.sort(Comparator.reverseOrder());
//		System.out.println(myList);
		
//		ArrayList<String> myList = new ArrayList<String>(Arrays.asList("Life", "is", "too", "short"));
//		System.out.println(String.join(" ", myList));
		
//		HashMap<String, Integer> grade = new HashMap<String, Integer>();
//		grade.put("A", 90);
//		grade.put("B", 80);
//		grade.put("C", 70);
//		System.out.println(grade.remove("B"));
		
//		ArrayList<Integer> nums = new ArrayList<Integer>(Arrays.asList(1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5));
//		//1
//		HashSet<Integer> tempNums = new HashSet<Integer>();
//		tempNums.addAll(nums);
//		System.out.println(tempNums);
//		//2
//		ArrayList<Integer> nums2 = new ArrayList<Integer>();
//		for (int i = 0; i < nums.size(); i++) {
//			if (!nums2.contains(nums.get(i))) {
//				nums2.add(nums.get(i));
//			}
//		}
//		System.out.println(nums2);
		
//		//TestCls cls = new TestCls();  // FM
//		//cls.printCoffeePrice(CoffeeType.AMERICANO);  // FM
//		printCoffeePrice(CoffeeType.AMERICANO);
//		printCoffeePrice(CoffeeType.ICE_AMERICANO);
//		printCoffeePrice(CoffeeType.CAFE_LATTE);
		
	}

//	static void printCoffeePrice(CoffeeType ct) {
//        HashMap<CoffeeType, Integer> priceMap = new HashMap<>();
//        priceMap.put(CoffeeType.AMERICANO, 3000);
//        priceMap.put(CoffeeType.ICE_AMERICANO, 4000);
//        priceMap.put(CoffeeType.CAFE_LATTE, 5000);
//        int price = priceMap.get(ct);
//        System.out.println(String.format("가격은 %d원 입니다.", price));
//    }

//	enum CoffeeType {
//		AMERICANO,
//		ICE_AMERICANO,
//		CAFE_LATTE
//	}

}
