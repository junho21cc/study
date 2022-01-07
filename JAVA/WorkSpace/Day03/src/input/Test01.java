package input;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		//System.in - 표준 입력 객체
		//.read() - 데이터를 1byte씩 읽어오는 명령
		
		//Scanner - 데이터를 읽어오기 위한 도구
		//	- 파일 , 문자열 , 입력스트림 , URL..
		
		//Scanner 만들기
		//내가 사용할때 메인메소드에서 한번만 만들면 된다.
		Scanner sc = new Scanner(System.in);
		
		//.next() - 한 단어를 읽어오는 명령
		// - 문자열 형태로 읽어온다.
		// - 단, 띄어쓰기 단위로 읽어온다.
		System.out.print("이름 입력 :");
		String name = sc.next();//띄어쓰기 전까지만 입력받는다.
		System.out.println("이름 : "+name);
		
		//buffer
		// - 데이터의 단위, 데이터의 처리 속도, 형식등이 서로 다른 두 장치나
		// 프로그램 사이에서 데이터를 주고받기 위한 목적으로 사용되는 임시 기억 장치
		
		// - 컴퓨터에서 키보드 입력시에는 데이터를 공백문자를 기준으로 데이터를
		//   구분짓는다..
		//   스페이스, 탭, 엔터..
		
		//JAVA에서의 메소드명은 첫글자는 소문자 달라지는 단어의 첫글자 대문자
		//정수, 실수..
		//.next자료형();
		System.out.print("나이 입력 :");
		int age = sc.nextInt();
		System.out.println("나이 : "+age);
		
		System.out.print("키 입력 :");
		double hei = sc.nextDouble();
		System.out.println("키 : "+hei);
		
		//.nextLine() - 한 줄을 읽어오는 명령
		// - 단, \n(엔터)단위로 읽어온다.
		// - 띄어쓰기 기준으로 읽어오는것이 아니라..\n기준으로 데이터를 읽어온다.
		// - 무언가를 입력받은 후에 nextLine을 사용하면 버퍼에 \n이 남아있기때문에
		//   데이터를 입력받은 걸로 인식한다.. 버퍼안에 엔터값을 제거해줘야한다.
		//			.nextLine()을 한번 더 적는다.
		sc.nextLine();//버퍼안에 \n을 비워준다.
		System.out.println("아무거나 써보세요..");
		String str = sc.nextLine();
		System.out.println("str = "+str);
	}

}
