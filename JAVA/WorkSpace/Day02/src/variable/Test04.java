package variable;

public class Test04 {

	public static void main(String[] args) {
		//String - ���ڿ�
		// - ������
		// - ������ �Ϲݺ���ó�� �������..
		// - ���ڿ��� �����ϱ� ���ؼ� ""(�ֵ���ǥ)�ȿ� �����Ѵ�.
		
		String name = "ȫ�浿";
		System.out.println(name);
		
		//���ڿ��� ������ �Ұ����ϴ�..
		// ��, ���ڿ� ���ϱ�� �����ϴ�..
		// ���ڿ� ���ϱ�� ���ڿ� �ڿ� ���ڿ��� �ٿ��ش�..(�̾���̱�)
		
		System.out.println(name + "���ϱ�");
		//"ȫ�浿" + "���ϱ�" = "ȫ�浿���ϱ�"
		System.out.println(name + 10);
		//"ȫ�浿" + 10 = "ȫ�浿10"
		System.out.println(name + 10+20);
		//"ȫ�浿" + 10 + 20 = "ȫ�浿1020"
		System.out.println(name + (10+20));
		//"ȫ�浿" + (10+20) -> "ȫ�浿" + 30 -> "ȫ�浿30"
		System.out.println(10+20+"ȫ�浿");
	}

}
