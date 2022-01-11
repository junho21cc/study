package switchcase;

import java.util.Scanner;

public class Test03 {

	public static void main(String[] args) {
//		여행사 경품추첨 프로그램
		//	사용자에게 여행가고 싶은 달을 숫자로 입력받아(1 ~ 12)
		//	해당하는 계절에 맞는 사은품을 증정한다는 메세지를 출력......
		//
		//	(예상 결과)	
		//	여행 가고싶은 달 입력 : 5
		//	봄에 여행가시면 황사마스크를 사은품으로 증정합니다!
		//	받으시려면 여기를 누르세요...
		//
		//	[계절별 사은품]	
		//			봄 	- 황사마스크 3,4,5
		//			여름 	- 모기퇴치약 6,7,8
		//			가을	- 선글라스 9,10,11
		//			겨울	- 머플러 12,1,2
		
		Scanner sc = new Scanner(System.in);
		System.out.print("여행 가고 싶은 달 입력 :");
		int month = sc.nextInt();
		
		switch(month) {
		case 3:case 4:case 5:
			System.out.println("봄에 여행가시면 황사마스크를 사은품으로 증정합니다!");
			break;
		case 6:case 7:case 8:
			System.out.println("여름에 여행가시면 모기퇴치약을 사은품으로 증정합니다!");
			break;
		case 9:case 10:case 11:
			System.out.println("가을에 여행가시면 선글라스를 사은품으로 증정합니다 !");
			break;
		case 12:case 1:case 2:
			System.out.println("겨울에 여행가시면 머플러를 사은품으로 증정합니다!");
			break;
		default:
			System.out.println("잘못된 달 입력 !");
		}

	}

}
