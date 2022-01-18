package forloop;

public class Test02 {

	public static void main(String[] args) {
//		돈을 저축하려 합니다
//		오늘 저축할 돈은 어제 저축한 돈의 두배로 할 예정이고
//		첫째날에 1원을 저축하려고 합니다
//
//		(Q1)	30일동안 통장에 저축될 돈은 얼마입니까?
		int cost = 1;//통장에 넣을 돈
		int tot = 0;//통장
		for(int i=0;i<30;i++) {
			tot += cost;//tot = tot + cost;
			cost *= 2;
		}
		System.out.println(tot);
		
//		(Q2)	40일동안 통장에 저축될 돈은 얼마입니까?
		long tot1 = 0;
		//long cost1 = 1;
		for(long i=0 , cost1 = 1; i<40; i++, cost1 *= 2) {
			tot1 += cost1;
			//cost1 *= 2;
		}
		System.out.println(tot1);
		//for문은 초기식이 1개이상, 증감식이 1개 이상이 가능하다.
		//단 , 조건식은 1개여야한다.
	}

}
