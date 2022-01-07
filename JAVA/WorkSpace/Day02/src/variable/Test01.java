package variable;

public class Test01 {

	public static void main(String[] args) {
		//실수
		
		//실수형 자료형 - double	유효자리수
		// float 	4byte		7자리
		// double	8byte		15자리
		
		float a = 123.456f;//float의 특징은 실수뒤에 f붙여서 값을 초기화해야한다.
		//실수형 상수는 기본적으로 double형
		//float으로 인식시키려면 상수뒤에 f를 적어주면된다.
		double d = 123.456;
		
		//1.자료형이 큰쪽에서 작은쪽으로 이동하려할때는 Error발생
		// - 같은 크기라면 정수보다 실수가 크다
		// - 조금이라도 데이터의 손실이 발생될 수 있는 상황이라면 eclipse에서
		//   오류가난다.(알려준다)
		
		// double > long > float > int > short == char > byte
		
		// CAST 연산자
		// (자료형)상수,변수,(연산식)
		// - 내가 원하는 데이터 타입으로 데이터를 일시적으로 변환시키는 연산자
		
		//a = 20; float자료형에 정수 20 -> 20.0 ( 작은쪽에서 큰쪽으로 대입되었기때문에 )
		//System.out.println(a);
		
		//int b = a; int자료형에 float 20.0 x ( 큰쪽에서 작은쪽으로 대입되었기때문에 )
		
		int b = (int)a;
		System.out.println(b);
		
		// 2. 실수가 한개라도 포함된 연산에서는 실수값이 나온다..
		int kor = 60;
		int eng = 13;
		int math = 98;
		int sub = 3;//과목의 개수
		System.out.println((kor+eng) / 2);//(정수+정수) / 정수
		System.out.println((kor+eng) / 2.0);//(정수+정수) / 실수
		System.out.println((kor+eng+math) / sub);
		System.out.println((double)(kor+eng+math) / sub);
		System.out.println((kor+eng+math) / (double)sub);
		
		// 3. 정밀한 계산에서는 실수를 사용하지 않는다.
		System.out.println(1.3 % 0.2);
		
	}

}
