package switchcase;

import java.io.IOException;
import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//Ű �Է�
		//Q or q - SKILL1
		//W or w - SKILL2
		//E or e - SKILL3
		//R or r - SKILL4
		System.out.print("Ű �Է� :");
		char key = sc.next().charAt(0);//���� ù��° ���ڸ� �������� �޼ҵ�
		
		switch(Character.toLowerCase(key)) {//�빮�ڸ� �ҹ��ڷ� �ٲپ��ִ� �޼ҵ�
		case 'q':
			System.out.println("SKILL 1");
			break;
		case 'w':
			System.out.println("SKILL 2");
			break;
		case 'e':
			System.out.println("SKILL 3");
			break;
		case 'r':
			System.out.println("SKILL 4");
			break;
		default:
			System.out.println("�߸��� �Է�!");
		}
		
		System.out.print("Ű �Է� :");
		String key1 = sc.next();
		switch(key1) {
		case "Q":
		case "q":
			System.out.println("SKILL 1");
			break;
		case "W":
		case "w":
			System.out.println("SKILL 2");
			break;
		case "E":
		case "e":
			System.out.println("SKILL 3");
			break;
		case "R":
		case "r":
			System.out.println("SKILL 4");
			break;
		default:
			System.out.println("�߸��� ���� �Է� !");
		}
	}

}
