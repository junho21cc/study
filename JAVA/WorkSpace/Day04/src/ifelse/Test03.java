package ifelse;

import java.util.Scanner;

public class Test03 {

	public static void main(String[] args) {
		//로그인
		//1.아이디와 비밀번호를 입력받는다.
		//2. 입력받은 아이디와 비밀번호를 db데이터를 비교해 로그인 처리를 진행한다.
		//ex) 로그인 성공 or 로그인 실패
		int dbId = 1234;
		int dbPw = 1111;
		Scanner sc = new Scanner(System.in);
		System.out.print("아이디 입력 :");
		int userId = sc.nextInt();
		System.out.print("비밀번호 입력 :");
		int userPw = sc.nextInt();
		
//		if(userId == dbId && userPw == dbPw) {
//			System.out.println("로그인 성공!");
//		}
		if(userId == dbId) {
			if(userPw == dbPw) {
				System.out.println("로그인 성공!");
			}
			else {
				System.out.println("비밀번호가 다릅니다");
			}
		}
		else {
			System.out.println("아이디가 다릅니다");
		}
//		else {
//			System.out.println("로그인 실패!");
//		}
		if(userId != dbId || userPw != dbPw) {
			System.out.println("로그인 실패!");
		}
		
		//회원가입 후 로그인
		//1. 논리연산자
		
		//2. 외부if안에 내부if
		
	}

}
