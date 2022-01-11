package switchcase;

import java.io.IOException;
import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//키 입력
		//Q or q - SKILL1
		//W or w - SKILL2
		//E or e - SKILL3
		//R or r - SKILL4
		System.out.print("키 입력 :");
		char key = sc.next().charAt(0);//가장 첫번째 문자를 가져오는 메소드
		
		switch(Character.toLowerCase(key)) {//대문자를 소문자로 바꾸어주는 메소드
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
			System.out.println("잘못된 입력!");
		}
		
		System.out.print("키 입력 :");
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
			System.out.println("잘못된 문자 입력 !");
		}
	}

}
