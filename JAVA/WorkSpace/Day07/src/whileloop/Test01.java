package whileloop;

public class Test01 {

	public static void main(String[] args) {
		int i=1;//�ʱ��
		while(true) {//���ѹݺ�
			System.out.println("i = "+i);
			if(i == 7) {
				break;//�ݺ��� �������
			}
			i++;//i�� 1������
		}
		
		i = 1;//�ʱ��
		while(i <= 7) {//���ǽ�
			System.out.println("i = "+i);
			i++;//������
		}

	}

}
