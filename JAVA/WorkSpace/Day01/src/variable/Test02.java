package variable;

public class Test02 {

	public static void main(String[] args) {
		//������
		System.out.println(10);
		System.out.println(20);//�ܹ߼� ������
		
		//������ �ڷ���
		//byte		1byte	-2^7 ~ 2^7-1	-128~127
		//short		2byte	-2^15 ~ 2^15-1	-32768 ~ 32767
		//int		4byte	-2^31 ~ 2~31-1
		//long		8byte	-2^63 ~ 2^63-1
		
		//1bit - 0 or 1 ���� �ϳ��� ������ �� �ִ� ��ǻ���� �ּ� ������ ����
		//1bit * 8 = 1byte
		
		//byte b = 128; - byte�� 128 ũ���� ���ڸ� ���� x
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
