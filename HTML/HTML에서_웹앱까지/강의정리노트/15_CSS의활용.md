배경(background)
속성
	color: 배경색
	image: 배경 이미지 설정
	repeat: 설정된 배경 이미지의 반복 유무 설정
	position: direction direction(left center right, top center, bottom)
	attachment(배경 이미지를 스크롤과는 무관하게 해당 위치에 고정함)
	
박스 모델

크기단위: %, em, px, cm, mm, inch등
크기 속성: height, width, max-width, min-width, max-height, min-height

글자(text)
속성
	color: 글자색
	direction: 텍스트가 써지는 방향(ltr: left to right, rtl: right to left)
	letter-spacing: 텍스트 내에서 글자 사이의 간격 설정
	word-spacing: 텍스트 내에서 단어 사이의 간격 설정
	text속성: indent, align, decoration,transform, shadow
		indent: 들여쓰기
		align: 수평 방향정렬
		decoration: 여러가지 효과
		transform: 영어에 대소문자 설정
		shadow: 간단한 그림자 효과 설정
	line: 텍스트의 줄 간격 설정

박스 모델
패딩(padding): 내용과 테두리 사이의 간격, 눈에 보이지 않음(빈칸취급)
	속성: top, right, bottom, left ( 축약 표현: div.number(2~4) )
테두리(border): 내용과 패딩 주변을 감싸는 테두리(보편적으로 눈에 보이는 겉부분)
	style속성: dotted, dashed, solid, double, groove, ridge, inset, outset, none, hidden
		dotted: 테두리를 점선으로
		dashed: 테두리를 약간 긴 점선으로
		solid: 테두리를 실선으로
		double: 테두리를 이중 실선
		groove: 테두리를 3차원인 입체적인 선으로
		ridge: 테두리를 3차원인 능선효과가 있는 선으로
		inset: 테두리를 3차원인 내지로 끼운 선으로
		outset: 테두리를 3차원인 외지로 끼운 선으로
		none: 테두리가 없음
		hidden: 테두리가 존재하지만 표현되지않음
	width속성: thin, medium, thick
	color속성
마진(margin): 테두리와 이웃하는 요소 사이의 간격, 눈에 보이지 않음(빈칸취급)
내용(content): 텍스트나 이미지가 들어있는 박스의 실질적인 내용의 부분

