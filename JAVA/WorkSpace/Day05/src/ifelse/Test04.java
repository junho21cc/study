package ifelse;

public class Test04 {

	public static void main(String[] args) {
		//Math.random()
		// - 0���� 1�̸��� ������ �Ǽ��� ���ϴ� ���
		// - 0.0000 ~ 0.9999
		
		//���� ���ϴ� ������ ������ �� ���ϱ�
		// - (int)(Math.random() * ����) + ���ۼ�;
		int su = (int)(Math.random() * 3) + 9;//9 10 11
		//9~11���� ����
		
		double a = Math.random();//0.0000~0.9999
		double b = a*3;//0.0000~2.9999
		int c = (int)b;//0 ~ 2
		int d = c + 9;// 9 ~ 11
		System.out.println(d);
		
		//1~10
		int rand = (int)(Math.random()*10)+1;//1 2 3 4 5 6 7 8 9 10
		System.out.println(rand);
		//5~10
		int rand1 = (int)(Math.random()*6)+5;//5 6 7 8 9 10
		System.out.println(rand1);
		
	}

}
