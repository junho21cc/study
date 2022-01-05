package variable;

public class Test02 {

	public static void main(String[] args) {
		//정수형
		System.out.println(10);
		System.out.println(20);//단발성 데이터
		
		//정수형 자료형
		//byte		1byte	-2^7 ~ 2^7-1	-128~127
		//short		2byte	-2^15 ~ 2^15-1	-32768 ~ 32767
		//int		4byte	-2^31 ~ 2~31-1
		//long		8byte	-2^63 ~ 2^63-1
		
		//1bit - 0 or 1 둘중 하나를 저장할 수 있는 컴퓨터의 최소 데이터 단위
		//1bit * 8 = 1byte
		
		//byte b = 128; - byte는 128 크기의 숫자를 저장 x
		//short s = 128;
		//byte b = -128;
		//System.out.println(b);
		
		int a = 20;
		System.out.println(a);
		int b = 10;
		a = b;
		System.out.println(a);
		System.out.println(b);
	}

}
