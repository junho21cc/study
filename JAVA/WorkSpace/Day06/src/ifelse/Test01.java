package ifelse;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
//		화면에 무작위로 구구단 1문제를 출제(2단 ~ 15단)
	//	2 X 1 = 	부터 		15 X 9 = 		까지
	//	사용자가 정답을 입력할 수 있도록 프로그래밍 코드를 구현(Scanner)
	//	정답일 경우 아래와 같이 처리
	//
	//	[1] 맞춘 경우	정답! 10점 획득!
	//	[2] 틀린 경우	오답! 5점 감점!
	//
	//	추가적으로, 어려운 문제(11단 이상)을 맞추면 10점을 추가로 획득하도록 코드 구현
		Scanner sc = new Scanner(System.in);
		int dan = (int)(Math.random()*14) +2;//2~15
		int su = (int)(Math.random()*9)+1;//1~9
		int com = dan * su;
		System.out.print(dan+"x"+su+"=");
		int user = sc.nextInt();
		if(com == user) {
			System.out.println("정답 ! 10점 획득 !");
			if(dan >= 11) {
				System.out.println("어려운 문제! 10점 추가 획득 !");
			}
		}
		else {
			System.out.println("오답 ! 5점 감점 !");
		}
	}

}
