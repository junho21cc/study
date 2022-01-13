package whileloop;

public class Test03 {

	public static void main(String[] args) {
//		[ 아이템 강화 시뮬레이션 ]
//		1. 아이템은 1번 강화하는데 현금 1000원이 필요하다
//		2. 아이템은 처음에 레벨이 0이다
//		3. 강화가 성공할 확률은 35% 이고 성공하면 레벨이 1 증가
//		4. 강화가 실패할 확률은 30% 이고 실패하면 레벨이 1 감소
			//단, 0레벨일경우 레벨 감소 x
//		5. 그 외의 경우에는 아무런 변화가 없다	
//		0레벨의 아이템을 10레벨로 만들기 위해 내가 쏟아 부어야 되는 현금을 계산하세요
		int lev = 0;
		int price = 0;
		while(true) {
			int rate = (int)(Math.random() * 101);//0~100
			price+=1000;
			//성공확률 if
			if(rate < 35) {//0~34
				lev++;
				System.out.println("강화성공 ! 1레벨 증가! 레벨 : "+lev);
				if(lev == 10) {//종료지점
					System.out.println("강화 완료 !");
					System.out.println("총 금액  : "+price);
					break;
				}
			}
			//실패확률 if
			else if(rate>=70) {//70~100
				if(lev == 0) {
					System.out.println("강화 실패 ! 레벨이 0이므로 아무런 변화가 없습니다 !");
					continue;//밑에있는 모든 코드들을 실행하지않고 반복문 처음으로 돌아간다.
					//else대용으로 많이 사용된다.
				}
				//else {
					lev--;
					System.out.println("강화 실패 ! 1레벨 감소 ! 레벨 : "+lev);
				//}
			}
			//아무런변화x if
			else {
				System.out.println("아무런 변화가 없습니다 ! 레벨 : "+lev);
			}
			
			
		}
	}

}
